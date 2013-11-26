import FWCore.ParameterSet.Config as cms

process = cms.Process("USER")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.maxEvents = cms.untracked.PSet(
                    input = cms.untracked.int32(-1)
)
process.source = cms.Source("PoolSource",
        fileNames = cms.untracked.vstring('file:/uscms_data/d3/skaplan/JetFlavorStudies/CMSSW_5_3_13/src/Analyzers/JetMatchingAnalyzer/chadronghost_lighthadrondr_events.root')
)
process.printEventNumber = cms.OutputModule("AsciiOutputModule")

process.printList = cms.EDAnalyzer("ParticleListDrawer",
                    src = cms.InputTag("genParticles"),
                    maxEventsToPrint  = cms.untracked.int32(-1)
)

process.p = cms.Path(process.printList)

process.outpath = cms.EndPath(process.printEventNumber)
process.MessageLogger.destinations = cms.untracked.vstring('cout','cerr')
