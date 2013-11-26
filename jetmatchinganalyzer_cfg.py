from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing ('python')

options.register('jetType',
                 "GenJets",
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
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/30CC0B1E-2B16-E211-BF1D-90E6BA442EEC.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/320DC34E-D815-E211-8D56-00259073E3F0.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3215986E-F415-E211-AA99-00261834B561.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3239B0CC-4516-E211-A761-90E6BA19A212.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3272AD25-3E16-E211-9B94-90E6BA442F25.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3278A2C8-3B16-E211-974A-00259074AE40.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/328D1D48-AA15-E211-860D-00259073E3F2.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/32AA8F6D-FA15-E211-AD91-20CF3027A633.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/32B57A3E-7F15-E211-AFD3-E0CB4E19F970.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/342F9EE3-1616-E211-83F9-20CF305B0590.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3437D2C7-F115-E211-9CCE-20CF300E9ECB.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3463CB87-CB15-E211-97FD-20CF3056171C.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/34D70102-E815-E211-8624-20CF3027A5AF.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/34DF681D-A915-E211-B066-0030487E3026.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/361C433C-2516-E211-AC08-20CF3027A608.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3622D000-CE15-E211-93A3-001EC9D7FA2C.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/363148F5-ED15-E211-83E8-00259073E438.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/36627C46-FB15-E211-B6C4-00259073E47E.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/366B1737-1116-E211-9135-20CF305B0582.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/367DB251-3F16-E211-B195-90E6BA442F25.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/368FF732-2516-E211-9F67-485B39800B95.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/369C5993-DD15-E211-A94C-90E6BA442F3E.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/36C1F48A-1616-E211-9914-00259073E3D2.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/36C26A30-4016-E211-8C50-00259073E4A2.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/36E89A95-2A16-E211-96F6-E0CB4E29C4C6.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/38021A03-2716-E211-B939-90E6BA19A248.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3861CD11-1F16-E211-8FCB-E0CB4E29C514.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/389A9DB8-A615-E211-9D50-00259073E51C.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/38A4C291-A315-E211-B94D-E0CB4E55366B.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/38A957AE-3716-E211-97E1-90E6BA442F07.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/38B535BC-2616-E211-9018-001EC9D825CD.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3A5972B0-DC15-E211-B62F-00259073E406.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3A925D17-0B16-E211-90C2-BCAEC50971F9.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3ACC86DE-3A16-E211-B824-485B39800BED.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3C02529A-8115-E211-8B72-00259073E4E6.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3C095702-F915-E211-B467-20CF3027A62F.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3C0E2F9E-D015-E211-BDC1-90E6BA0D09AF.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3C286383-9815-E211-B104-001E4F3F28D8.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3C61CB36-2016-E211-AFCC-90E6BA442F02.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3C6E9E4E-DD15-E211-94D5-001EC9D82BBB.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3C9A5FDE-1416-E211-AE96-00259073E390.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3CA43D95-2A16-E211-9A08-E0CB4E19F962.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3CB2F540-1D16-E211-8B63-20CF305616E1.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3CB5BBB4-2616-E211-B201-20CF30724B0A.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3CBA8E35-0016-E211-AC9D-485B39800C0F.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3CCE52DD-0216-E211-85F6-00259074AE8C.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3CF12735-D115-E211-863A-E0CB4E19F995.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E1BDD87-7515-E211-B771-20CF3027A633.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E3267DE-1316-E211-BC4E-00259073E322.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E3F9E65-1616-E211-9B01-00259073E4D6.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E494F16-3C16-E211-AE61-002590747DD8.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E55892F-A115-E211-94D0-E0CB4E1A1174.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E7048FD-B215-E211-8D5D-00259073E526.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E7798E1-3F16-E211-A283-001EC9D28298.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E7A876F-6615-E211-AB39-00259073E504.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E819ABD-8015-E211-ADFB-00259073E4FC.root',
          '/store/mc/Summer12_DR53X/TTJets_HadronicMGDecays_8TeV-madgraph/AODSIM/PU_S10_START53_V7A-v1/00000/3E871C13-7B15-E211-8D93-90E6BA442EF1.root'
    )
                            )
process.myPartons = cms.EDProducer("PartonSelector",
    src = cms.InputTag("genParticles"),
    withLeptons = cms.bool(False)
)

process.flavourByRefAK5 = cms.EDProducer("JetPartonMatcher",
      jets = cms.InputTag("ak5"+options.jetType),
      coneSizeToAssociate = cms.double(0.3),
      partons = cms.InputTag("myPartons")
)
process.flavourByRefKT6 = cms.EDProducer("JetPartonMatcher",
      jets = cms.InputTag("kt6"+options.jetType),
      coneSizeToAssociate = cms.double(0.3),
      partons = cms.InputTag("myPartons")
      )
process.selectedHadronsAndPartons = cms.EDProducer('HadronAndPartonSelector',
           src = cms.InputTag("generator"),
           particles = cms.InputTag("genParticles"),
           partonMode = cms.string("Auto")
   )

process.jetFlavourInfosAK5 = cms.EDProducer("JetFlavourClustering",
     jets           = cms.InputTag("ak5"+options.jetType),
     bHadrons       = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
     cHadrons       = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
     partons        = cms.InputTag("selectedHadronsAndPartons","partons"),
     jetAlgorithm   = cms.string("AntiKt"),
     rParam         = cms.double(0.5),
     jetPtMin       = cms.double(0.),
     ghostRescaling = cms.double(1e-18),
     useEtaPhiDistance = cms.bool(False)
)
process.jetFlavourInfosKT6 = cms.EDProducer("JetFlavourClustering",
     jets           = cms.InputTag("kt6"+options.jetType),
     bHadrons       = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
     cHadrons       = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
     partons        = cms.InputTag("selectedHadronsAndPartons","partons"),
     jetAlgorithm   = cms.string("Kt"),
     rParam         = cms.double(0.6),
     jetPtMin       = cms.double(0.),
     ghostRescaling = cms.double(1e-18),
     useEtaPhiDistance = cms.bool(False)
     )
process.TFileService = cms.Service("TFileService",
      fileName = cms.string(options.outfilename)
)
process.analyzerAK5 = cms.EDAnalyzer('JetMatchingAnalyzer',
          particleSource = cms.InputTag("genParticles"),
          srcByRef = cms.InputTag("flavourByRefAK5"),
          jetFlavourInfos = cms.InputTag("jetFlavourInfosAK5"),
          hadronMatchDr = cms.double(0.3),
          jetPtCut = cms.double(0.0)
)
process.analyzerKT6 = cms.EDAnalyzer('JetMatchingAnalyzer',
          particleSource = cms.InputTag("genParticles"),
          srcByRef = cms.InputTag("flavourByRefKT6"),
          jetFlavourInfos = cms.InputTag("jetFlavourInfosKT6"),
          hadronMatchDr = cms.double(0.3),
          jetPtCut = cms.double(0.0)
          )

process.p = cms.Path(process.myPartons+process.selectedHadronsAndPartons*process.flavourByRefAK5+process.flavourByRefKT6*process.jetFlavourInfosAK5+process.jetFlavourInfosKT6*process.analyzerAK5+process.analyzerKT6)
