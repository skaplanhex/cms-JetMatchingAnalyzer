from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing ('python')

options.register('jetType',
                 "PFJets",
                 VarParsing.multiplicity.singleton,
                 VarParsing.varType.string,
                 "Jet type to be used in the event"
                 )
options.register('outfilename',
                 "outfile.root",
                 VarParsing.multiplicity.singleton,
                 VarParsing.varType.string,
                 "Name of output file"
                 )
options.register('useSubjets',
                  False,
                  VarParsing.multiplicity.singleton,
                  VarParsing.varType.bool,
                  'Whether or not to analyze subjet based tagging'
                  )
## 'maxEvents' and 'outputFile' are already registered by the Framework, changing default value
options.setDefault('maxEvents', 15)
#options.setDefault('outputFile', 'jetmatchingplots.root')
options.parseArguments()
import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents ))

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
#          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/0007F60C-D49C-E211-BD33-00266CFFA1E4.root',
#          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/44517A43-EA9C-E211-99B5-00266CFFA418.root',
#          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/92BAFDF6-E79C-E211-AEF1-00266CFFB1F4.root',
#          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/FEFB984B-F09C-E211-8BD5-00266CFFA754.root')
          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/1066A0AC-F29C-E211-AC60-00266CFFA1E4.root',
          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/14C63C8A-DD9C-E211-A8F3-00266CFFA750.root',
          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/B4A4ACF8-CB9C-E211-9BE3-00266CFFA604.root',
          '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/E4F843C9-DF9C-E211-BF01-00266CFFA1E4.root')
                )
process.myPartons = cms.EDProducer("PartonSelector",
    src = cms.InputTag("genParticles"),
    withLeptons = cms.bool(False)
)

from RecoJets.JetProducers.ak5PFJetsFiltered_cfi import ak5PFJets
process.ak8PFJets = ak5PFJets.clone(
            rParam              = cms.double(0.8),
            src                 = cms.InputTag("particleFlow"),
            )

from RecoJets.JetProducers.ak5PFJetsFiltered_cfi import ak5PFJetsFiltered
process.ak8PFJetsFiltered = ak5PFJetsFiltered.clone(
            rParam              = cms.double(0.8),
            src                 = cms.InputTag("particleFlow"),
            writeCompound       = cms.bool(True),
            jetCollInstanceName = cms.string("SubJets")
            )
#process.flavourByRefKT6 = cms.EDProducer("JetPartonMatcher",
#      jets = cms.InputTag("kt6"+options.jetType),
#      coneSizeToAssociate = cms.double(0.3),
#      partons = cms.InputTag("myPartons")
#      )
process.selectedHadronsAndPartons = cms.EDProducer('HadronAndPartonSelector',
           src = cms.InputTag("generator"),
           particles = cms.InputTag("genParticles"),
           partonMode = cms.string("Auto")
   )
process.flavourByRefAK8 = cms.EDProducer("JetPartonMatcher",
     jets = cms.InputTag("ak8PFJets"),
     coneSizeToAssociate = cms.double(0.3),
     partons = cms.InputTag("myPartons")
     )
process.flavourByRefAK8Subjets = cms.EDProducer("JetPartonMatcher",
     jets = cms.InputTag("ak8PFJetsFiltered", "SubJets"),
     coneSizeToAssociate = cms.double(0.3),
     partons = cms.InputTag("myPartons")
     )
#process.jetFlavourInfosAK8PFJets = cms.EDProducer("JetFlavourClustering",
#     jets           = cms.InputTag("ak8PFJets"),
#     bHadrons       = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
#     cHadrons       = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
#     partons        = cms.InputTag("selectedHadronsAndPartons","partons"),
#     jetAlgorithm   = cms.string("AntiKt"),
#     rParam         = cms.double(0.5),
#     jetPtMin       = cms.double(0.),
#     ghostRescaling = cms.double(1e-18),
#     useEtaPhiDistance = cms.bool(False)
#)

#for the higgs sample

process.jetFlavourInfosAK8PFJets = cms.EDProducer("JetFlavourClustering",
      jets                     = cms.InputTag("ak8PFJets"),
      groomedJets              = cms.InputTag("ak8PFJetsFiltered"),
      subjets                  = cms.InputTag("ak8PFJetsFiltered", "SubJets"),
      bHadrons                 = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
      cHadrons                 = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
      partons                  = cms.InputTag("selectedHadronsAndPartons","partons"),
      jetAlgorithm             = cms.string("AntiKt"),
      rParam                   = cms.double(0.8),
      ghostRescaling           = cms.double(1e-18),
      hadronFlavourHasPriority = cms.bool(True)
      )
#for the top sample
#from RecoJets.JetProducers.AnomalousCellParameters_cfi import *
#from RecoJets.JetProducers.CATopJetParameters_cfi import *
#from RecoJets.JetProducers.PFJetParameters_cfi import *
#
#from RecoJets.JetProducers.ca4PFJets_cfi import ca4PFJets
#process.ca15PFJetsPFlow = ca4PFJets.clone(
#     rParam = cms.double(1.5),
#     src = cms.InputTag("particleFlow"),
#     doAreaFastjet = cms.bool(True),
#     doRhoFastjet = cms.bool(True),
#     Rho_EtaMax = cms.double(6.0),
#     Ghost_EtaMax = cms.double(7.0)
#     )
#process.caTopTagPFlow = cms.EDProducer(
#       "CATopJetProducer",
#       PFJetParameters.clone( src = cms.InputTag("particleFlow"),
#                             doAreaFastjet = cms.bool(False),
#                             doRhoFastjet = cms.bool(False),
#                             jetPtMin = cms.double(100.0)
#                             ),
#       AnomalousCellParameters,
#       CATopJetParameters,
#       jetAlgorithm = cms.string("CambridgeAachen"),
#       rParam = cms.double(0.8),
#       writeCompound = cms.bool(True)
#       )
#process.caHEPTopTagPFlow = process.caTopTagPFlow.clone(
#       rParam = cms.double(1.5),
#       tagAlgo = cms.int32(2)
#       )
#
#process.jetFlavourInfosAK8PFJets = cms.EDProducer("JetFlavourClustering",
#          jets                     = cms.InputTag("ak8PFJets"),
#          groomedJets              = cms.InputTag("ak8PFJetsFiltered"),
#          subjets                  = cms.InputTag("ak8PFJetsFiltered", "SubJets"),
#          bHadrons                 = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
#          cHadrons                 = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
#          partons                  = cms.InputTag("selectedHadronsAndPartons","partons"),
#          jetAlgorithm             = cms.string("AntiKt"),
#          rParam                   = cms.double(0.8),
#          ghostRescaling           = cms.double(1e-18),
#          hadronFlavourHasPriority = cms.bool(True)
#)
#process.jetFlavourInfosCA15PFJets = cms.EDProducer("JetFlavourClustering",
#          jets                     = cms.InputTag("ca15PFJetsPFlow"),
#          groomedJets              = cms.InputTag("caHEPTopTagPFlow"),
#          subjets                  = cms.InputTag("caHEPTopTagPFlow", "SubJets"),
#          bHadrons                 = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
#          cHadrons                 = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
#          partons                  = cms.InputTag("selectedHadronsAndPartons","partons"),
#          jetAlgorithm             = cms.string("CambridgeAachen"),
#          rParam                   = cms.double(1.5),
#          ghostRescaling           = cms.double(1e-18),
#          hadronFlavourHasPriority = cms.bool(True)
#          )

process.TFileService = cms.Service("TFileService",
      fileName = cms.string(options.outfilename)
)
process.analyzerAK8 = cms.EDAnalyzer('JetMatchingAnalyzer',
         particleSource = cms.InputTag("genParticles"),
         jetFlavourByRef = cms.InputTag("flavourByRefAK8"),
         jetFlavourInfos = cms.InputTag("jetFlavourInfosAK8PFJets"),
         useSubjets = cms.bool(False),
         hadronMatchDr = cms.double(0.3),
         jetPtCut = cms.double(0.0)
)
process.analyzerAK8Subjets = cms.EDAnalyzer('JetMatchingAnalyzer',
         particleSource = cms.InputTag("genParticles"),
         jets = cms.InputTag("ak8PFJets"),
         groomedJets = cms.InputTag("ak8PFJetsFiltered"),
         jetFlavourByRef = cms.InputTag("flavourByRefAK8"),
         subjetFlavourByRef = cms.InputTag("flavourByRefAK8Subjets"),
         jetFlavourInfos = cms.InputTag("jetFlavourInfosAK8PFJets"),
         subjetFlavourInfos = cms.InputTag("jetFlavourInfosAK8PFJets","SubJets"),
         useSubjets = cms.bool(True),
         heavyID = cms.int32(25),
         hadronMatchDr = cms.double(0.3),
         jetPtCut = cms.double(0.0)
)



#### CHECK THIS LATER #####
#     |
#     |
#     |
#     V
#process.analyzerAK8 = cms.EDAnalyzer('JetMatchingAnalyzer',
#          particleSource = cms.InputTag("genParticles"),
#          jets = cms.InputTag("ak8PFJets"),
#          groomedJets = cms.InputTag("ak8PFJetsFiltered"),
#          srcByRef = cms.InputTag("flavourByRefAK8"),
#          jetFlavourInfos = cms.InputTag("jetFlavourInfosAK8PFJets");
#          useSubjets = cms.bool(True),
#          subjetFlavourInfos = cms.InputTag("jetFlavourInfosAK8PFJets","SubJets"),
#          hadronMatchDr = cms.double(0.3),
#          jetPtCut = cms.double(0.0)
#)
#process.analyzerCA15 = cms.EDAnalyzer('JetMatchingAnalyzer',
#         particleSource = cms.InputTag("genParticles"),
#         srcByRef = cms.InputTag("flavourByRefAK5"),
#         jetFlavourInfos = cms.InputTag("jetFlavourInfosCA15"),
#         hadronMatchDr = cms.double(0.3),
#         jetPtCut = cms.double(0.0)
#         )

process.p = cms.Path((process.myPartons+process.selectedHadronsAndPartons)*process.ak8PFJets*process.ak8PFJetsFiltered*(process.flavourByRefAK8+process.flavourByRefAK8Subjets)*process.jetFlavourInfosAK8PFJets*(process.analyzerAK8+process.analyzerAK8Subjets))