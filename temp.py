from ROOT import *
gROOT.SetStyle("Plain")
#SetBatch() makes it so the picture isn't displayed on the screen when saved; this saves lots of time!
gROOT.SetBatch()
#gStyle.SetOptStat(0)
c = TCanvas()
c.SetBorderMode(0)
c.SetFillColor(kWhite)
f = TFile("topplotsfeb3.root","READ")
histNew = f.Get("analyzerCA15Subjets/numBSubjets_JetPt")
histOld = f.Get("analyzerCA15Subjets/numBSubjets_JetPt_Old")
#hist = f.Get("analyzerPT0/hJetPt")
#hist.SetTitle("pT of ak5GenJets Not Matched To A Parton")
counter=0
for hist in (histNew,histOld):
	counter += 1
	temphist=hist.ProjectionX()
	temphist.SetTitle("Number of B Flavored Subjets")
	temphist.Draw()
	tempstring = ""
	if (counter == 1):
		tempstring = "New"
	elif (counter == 2):
		tempstring = "Old"
	c.SaveAs("numBSubjets"+tempstring+".png")
	c.Clear()

# hist.GetXaxis().SetTitle("Hadron Ghost Type")
# hist.GetYaxis().SetTitle("Parton Ghost Type")
# for partonBin in (1,2,3):
#     numMatchedToParton = hist.Integral(partonBin,partonBin,1,3)
#     for hadronBin in (1,2,3):
#         initialContent = hist.GetBinContent(partonBin,hadronBin)
#         newContent = float(initialContent)/float(numMatchedToParton);
#         hist.SetBinContent(partonBin,hadronBin,newContent)
# #hist.GetXaxis().SetRangeUser(0,15);
# #hist.GetYaxis().SetTitleOffset(1.4)
# hist.Draw("colztext")
# c.SaveAs("hadronpartonmatchmatrix.png")