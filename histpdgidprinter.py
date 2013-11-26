from ROOT import *

f = TFile("GenJetInvestigation.root",'read')
hist = f.Get('analyzer/genJetConstituentType')
for iBin in range(hist.GetNbinsX+2):
    pdgid = iBin-1
    numParticles = hist.GetBinContent(iBin)
    if numParticles == 0:
        continue
    else:
        print "# of particles with pdgid of",pdgid,":",numParticles