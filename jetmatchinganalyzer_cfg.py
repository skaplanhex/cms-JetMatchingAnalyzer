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
                            fileNames = cms.untracked.vstring('/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/107C9DC8-93D2-E111-A324-003048C693F8.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/108DAD96-A4D2-E111-A4A1-0030487D5D91.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/10BC6A16-06D3-E111-AC64-0030487D5EA1.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/10C1FA36-8CD3-E111-9CEA-0025904B144A.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/10D4FA98-7BD3-E111-BF7E-0030487F1C57.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/10E175EF-3ED2-E111-ADD6-003048C662BC.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/10F9169E-8BD2-E111-958D-0030487F1309.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/122579ED-C9D2-E111-8638-003048F0E832.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1284BB7E-AAD3-E111-A785-002481E0D480.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/12A8BC02-9DD3-E111-BE0E-00266CF33340.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/12E9DA5F-13D3-E111-8873-0030487D5E73.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/144BCEF0-ACD3-E111-A21E-003048F0E55A.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1460E1B8-C7D2-E111-A057-0025901D4B22.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/148CC183-4BD2-E111-842F-D8D385FF6C5E.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1499207A-B0D3-E111-BE28-0025904B1420.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/14F9B82E-8CD2-E111-93D3-0030487D5D8D.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/161E07E5-7DD3-E111-ADE9-00215AD4D6C8.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1627FC6A-64D2-E111-A61E-0030487F1A4F.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/163D10F8-8DD3-E111-ACE0-0030487D8121.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1648337E-7FD3-E111-A76D-0030487F1715.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1664F3C5-61D2-E111-A273-0030487F91DB.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/167DA133-C7D3-E111-93C5-002481E0DA96.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16888C4E-CAD3-E111-9B4C-D8D385FF6C5E.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16B77268-7DD3-E111-A34C-002481E0DC4C.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16C81546-C3D3-E111-A17F-003048F0E826.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16CBF3FD-9ED2-E111-A6A3-003048C68A80.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16D52DE5-BDD3-E111-83C3-0030487F1A31.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16D8B32E-BAD2-E111-B64E-00266CF32EAC.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16E94B2C-C7D3-E111-8C13-00266CF3336C.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/16F3DFEB-D2D3-E111-8678-0025901D4C32.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1804C3B0-27D3-E111-8B01-002590494C94.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/182A9D2E-E7D1-E111-A8E4-0030487E54B7.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/184997EF-D3D3-E111-9451-0030487D7103.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1866D27F-DDD2-E111-A0EE-0030487F929D.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/187E23A7-DDD3-E111-B4FC-00266CF330D8.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/188F4EBC-2ED2-E111-9A2B-0025901D4AFE.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1A0988D2-3AD2-E111-83EF-0030487F92AD.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1A1F0954-36D2-E111-8AA6-0030487F0EDD.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1A288C15-ABD3-E111-88A2-002481E0D5CE.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1A5D1486-AFD3-E111-85C9-0025901D4B06.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1A65743B-24D3-E111-8897-0025904B1364.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1A84FAE0-43D2-E111-B591-0030487E0A2D.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1A8ABB66-A0D3-E111-91CA-0030487F933F.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1AA94160-C1D2-E111-A02C-003048F0E826.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1AEF3FAB-AED3-E111-9A65-00266CF330D8.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1C0BF3E4-D0D3-E111-AA6E-003048D438EA.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1C0C5FF9-B8D3-E111-9695-003048C66BBE.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1C2CDED3-54D2-E111-A16D-003048D43942.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1C92E653-5BD3-E111-BE7B-0030487D5EA9.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1C932CBB-A3D2-E111-B759-0030487F1BD7.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1C9EBCF6-50D1-E111-A5A1-0030487F164D.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1CD91A57-91D3-E111-906E-003048F0E1EC.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1CDD8544-35D3-E111-A2E4-003048CEFFE4.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1E1385DA-5ED2-E111-A760-003048C6903C.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1E3864A6-C5D2-E111-BDA5-003048C6929A.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1E3F2EF6-3FD3-E111-AE2E-00266CF32EAC.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1E417980-37D2-E111-B9D3-0030487E55C5.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1E482A19-0ED3-E111-822B-0030487F1C51.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1E7869A9-BED2-E111-8EE8-0030487F929D.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/1EB8DDFC-34D2-E111-807A-0030487D7B79.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/20085EA9-ECD2-E111-9CBC-0030487F1737.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/20256D89-59D2-E111-898B-003048C69416.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/202847D3-6DD3-E111-9D24-0030487D5059.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/20311649-E4D2-E111-998A-0030487D5DC7.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/2098E326-D9D0-E111-9918-003048F0E1AC.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/20EAC743-DAD1-E111-AA03-003048D3CDE0.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22047ED9-49D2-E111-946D-0030487F1BE5.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/220EBE4D-77D2-E111-BA76-003048D47776.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/2212D71D-D9D3-E111-826F-003048C692D4.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/223EA962-B0D2-E111-9F76-003048C6903C.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/224B2184-77D3-E111-A2B3-0025901D4D6E.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/2257D5DC-CCD3-E111-8B98-003048F0E838.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22590630-29D3-E111-ACBD-0030487EBB27.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/225E9FD0-85D3-E111-9607-003048C6942A.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22644D45-E0D2-E111-B7F6-003048C6903A.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22759220-5AD2-E111-8714-00266CF3322C.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22871ABF-44D2-E111-9FD3-00215AD4D6C8.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/228A343A-83D3-E111-917E-003048C693E4.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22B68C44-95D3-E111-BBE4-0030487F16BF.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22B6C123-4FD3-E111-81D5-003048D4363C.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22D6A6CC-CDD3-E111-AF92-0030487D83B9.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/22F2A434-56D3-E111-8357-003048D43724.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/245942F6-CAD2-E111-81AF-0030487F171D.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/24685224-4BD3-E111-9907-003048C692B4.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/2488F61F-18D3-E111-8E5D-0030487EB003.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/249D2AA7-52D2-E111-95F5-002481E0D714.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/24BEE9CE-17D3-E111-9689-002481E94C7A.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/24DFF721-B3D3-E111-BC46-0030487F929B.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/268A6602-62D3-E111-865A-0030487F88EB.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/269A9572-EAD2-E111-AD4A-0030487F1661.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/26C64A10-C0D3-E111-A881-003048C693FE.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/26D37325-4DD3-E111-AE2A-0030487D5D91.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/26D5165E-F7D2-E111-974F-0030487E0A29.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/26F1C6B7-80D3-E111-8E81-0030487D5DC7.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/281F04C5-75D2-E111-B2E2-003048D43942.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/2877B0F2-BFD3-E111-9771-0025901D4B08.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/28795A64-5DD2-E111-9023-003048C662BC.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/288723D0-97D2-E111-85E2-003048D3CA06.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/28B8D74B-36D3-E111-9517-003048C662BC.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/28C9925D-40D2-E111-8697-003048D436E2.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/2A3D945F-9DD3-E111-95AE-0030487F1A55.root',
                                                              '/store/mc/Summer12_DR53X/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/0000/2A5EA8E0-56D2-E111-BC30-0030487D5EA1.root')
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
#process.jetFlavourInfosKT6 = cms.EDProducer("JetFlavourClustering",
#     jets           = cms.InputTag("kt6"+options.jetType),
#     bHadrons       = cms.InputTag("selectedHadronsAndPartons","bHadrons"),
#     cHadrons       = cms.InputTag("selectedHadronsAndPartons","cHadrons"),
#     partons        = cms.InputTag("selectedHadronsAndPartons","partons"),
#     jetAlgorithm   = cms.string("Kt"),
#     rParam         = cms.double(0.6),
#     jetPtMin       = cms.double(0.),
#     ghostRescaling = cms.double(1e-18),
#     useEtaPhiDistance = cms.bool(False)
#     )
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
#process.analyzerKT6 = cms.EDAnalyzer('JetMatchingAnalyzer',
#          particleSource = cms.InputTag("genParticles"),
#          srcByRef = cms.InputTag("flavourByRefKT6"),
#          jetFlavourInfos = cms.InputTag("jetFlavourInfosKT6"),
#          hadronMatchDr = cms.double(0.3),
#          jetPtCut = cms.double(0.0)
#          )

process.p = cms.Path(process.myPartons+process.selectedHadronsAndPartons*process.flavourByRefAK5*process.jetFlavourInfosAK5*process.analyzerAK5)
