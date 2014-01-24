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
          # '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/0007F60C-D49C-E211-BD33-00266CFFA1E4.root',
          # '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/44517A43-EA9C-E211-99B5-00266CFFA418.root',
          # '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/92BAFDF6-E79C-E211-AEF1-00266CFFB1F4.root',
          # '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-2500_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/FEFB984B-F09C-E211-8BD5-00266CFFA754.root')
         '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/1066A0AC-F29C-E211-AC60-00266CFFA1E4.root',
         '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/14C63C8A-DD9C-E211-A8F3-00266CFFA750.root',
         '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/B4A4ACF8-CB9C-E211-9BE3-00266CFFA604.root',
         '/store/mc/Summer12_DR53X/RadionToHHTo4B_M-1000_TuneZ2star_8TeV-nm-madgraph/AODSIM/PU_S10_START53_V7C-v1/10000/E4F843C9-DF9C-E211-BF01-00266CFFA1E4.root')
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/04DB1D18-6FFC-E111-9BCC-00215E21D5BE.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/0E72AA57-2AFC-E111-B8CB-00215E21DDA4.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/20536CF2-2AFC-E111-9B66-00215E21D690.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/2CC681D3-28FC-E111-AA4C-00215E2211A0.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/3481A85B-11FC-E111-8C18-00215E21D942.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/609B1866-23FC-E111-A471-001A645C1660.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/643FECAA-26FC-E111-BFEB-00215E21EC4A.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/648C948C-27FC-E111-AE38-00215E2216A4.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/74B2C6CD-2DFC-E111-8C80-00215E21F18A.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/7618C717-30FC-E111-8684-00215E21F18A.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/9031D51B-2CFC-E111-8BF4-001A645C97F6.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/98351219-2CFC-E111-B786-00215E221C7A.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/9A69DCAD-1EFC-E111-96F0-001A645BF218.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/CAB0D0B7-1CFC-E111-A193-00215E22225C.root',
       # '/store/mc/Summer12_DR53X/ZPrimeToTTJets_M2000GeV_W200GeV_TuneZ2star_8TeV-madgraph-tauola/AODSIM/PU_S10_START53_V7A-v1/0000/DA135DED-0AFC-E111-8B09-001A645D01EC.root')
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
from RecoJets.JetProducers.ak5PFJetsPruned_cfi import ak5PFJetsPruned
process.ak8PFJetsPruned = ak5PFJetsPruned.clone(
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
     jets = cms.InputTag("ak8PFJetsPruned", "SubJets"),
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
      groomedJets              = cms.InputTag("ak8PFJetsPruned"),
      subjets                  = cms.InputTag("ak8PFJetsPruned", "SubJets"),
      bHadrons                 = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
      cHadrons                 = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
      partons                  = cms.InputTag("selectedHadronsAndPartons","partons"),
      jetAlgorithm             = cms.string("AntiKt"),
      rParam                   = cms.double(0.8),
      ghostRescaling           = cms.double(1e-18),
      hadronFlavourHasPriority = cms.bool(True)
      )
# for top tagging
from RecoJets.JetProducers.AnomalousCellParameters_cfi import *
from RecoJets.JetProducers.CATopJetParameters_cfi import *
from RecoJets.JetProducers.PFJetParameters_cfi import *

from RecoJets.JetProducers.ca4PFJets_cfi import ca4PFJets
process.ca15PFJets = ca4PFJets.clone(
    rParam   = cms.double(1.5),
    src      = cms.InputTag("particleFlow"),
    jetPtMin = cms.double(100.0)
)

process.caHEPTopTagJets = cms.EDProducer(
    "CATopJetProducer",
    PFJetParameters.clone( src = cms.InputTag("particleFlow"),
                           doAreaFastjet = cms.bool(False),
                           doRhoFastjet = cms.bool(False),
                           jetPtMin = cms.double(100.0)
                           ),
    AnomalousCellParameters,
    CATopJetParameters.clone( tagAlgo = cms.int32(2) ),
    jetAlgorithm = cms.string("CambridgeAachen"),
    rParam = cms.double(1.5),
    writeCompound = cms.bool(True)
)
process.flavourByRefCA15 = cms.EDProducer("JetPartonMatcher",
     jets = cms.InputTag("caHEPTopTagJets"),
     coneSizeToAssociate = cms.double(0.3),
     partons = cms.InputTag("myPartons")
     )
process.flavourByRefCA15Subjets = cms.EDProducer("JetPartonMatcher",
     jets = cms.InputTag("caHEPTopTagJets", "caTopSubJets"),
     coneSizeToAssociate = cms.double(0.3),
     partons = cms.InputTag("myPartons")
     )

process.jetFlavourInfosCA15PFJets = cms.EDProducer("JetFlavourClustering",
         jets                     = cms.InputTag("ca15PFJets"),
         groomedJets              = cms.InputTag("caHEPTopTagJets"),
         subjets                  = cms.InputTag("caHEPTopTagJets", "caTopSubJets"),
         bHadrons                 = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
         cHadrons                 = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
         partons                  = cms.InputTag("selectedHadronsAndPartons","partons"),
         jetAlgorithm             = cms.string("CambridgeAachen"),
         rParam                   = cms.double(1.5),
         ghostRescaling           = cms.double(1e-18),
         hadronFlavourHasPriority = cms.bool(True)
)


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
         groomedJets = cms.InputTag("ak8PFJetsPruned"),
         jetFlavourByRef = cms.InputTag("flavourByRefAK8"),
         subjetFlavourByRef = cms.InputTag("flavourByRefAK8Subjets"),
         jetFlavourInfos = cms.InputTag("jetFlavourInfosAK8PFJets"),
         subjetFlavourInfos = cms.InputTag("jetFlavourInfosAK8PFJets","SubJets"),
         useSubjets = cms.bool(True),
         heavyID = cms.int32(25),
         hadronMatchDr = cms.double(0.3),
         jetPtCut = cms.double(0.0)
)
process.analyzerCA15Subjets = cms.EDAnalyzer('JetMatchingAnalyzer',
         particleSource = cms.InputTag("genParticles"),
         jets = cms.InputTag("ca15PFJets"),
         groomedJets = cms.InputTag("caHEPTopTagJets"),
         jetFlavourByRef = cms.InputTag("flavourByRefCA15"),
         subjetFlavourByRef = cms.InputTag("flavourByRefCA15Subjets"),
         jetFlavourInfos = cms.InputTag("jetFlavourInfosCA15PFJets"),
         subjetFlavourInfos = cms.InputTag("jetFlavourInfosCA15PFJets","SubJets"),
         useSubjets = cms.bool(True),
         heavyID = cms.int32(6),
         hadronMatchDr = cms.double(0.3),
         jetPtCut = cms.double(0.0)
)

process.p = cms.Path((process.myPartons+process.selectedHadronsAndPartons
  *process.ak8PFJets*process.ak8PFJetsPruned*(process.flavourByRefAK8+process.flavourByRefAK8Subjets)*process.jetFlavourInfosAK8PFJets*(process.analyzerAK8+process.analyzerAK8Subjets)))
#*process.ca15PFJets*process.caHEPTopTagJets*(process.flavourByRefCA15+process.flavourByRefCA15Subjets)*process.jetFlavourInfosCA15PFJets)*process.analyzerCA15Subjets)