from ROOT import *
#gROOT.SetStyle("Plain")
#SetBatch() makes it so the picture isn't displayed on the screen when saved; this saves lots of time!
gROOT.SetBatch()
gStyle.SetOptStat(0)
c = TCanvas()
c.SetBorderMode(0)
c.SetFillColor(kWhite)
#topplots
ftop = TFile("topplots_ZPrimeM2000.root","READ")
histNew = ftop.Get("analyzerCA15Subjets/numBSubjets_JetPt")
histOld = ftop.Get("analyzerCA15Subjets/numBSubjets_JetPt_Old")
#hist = f.Get("analyzerPT0/hJetPt")
#hist.SetTitle("pT of ak5GenJets Not Matched To A Parton")
counter=0
for hist in (histNew,histOld):
	counter += 1
	temphist=hist.ProjectionX()
	temphist.SetTitle("Number of B Flavored Subjets")
	temphist.Draw("")
	temphist.Draw("9sametext0")
	tempstring = ""
	if (counter == 1):
		tempstring = "New"
	elif (counter == 2):
		tempstring = "Old"
	c.SaveAs("numBSubjets"+tempstring+".png")
	c.Clear()
#higgs plots
fhiggs = TFile("higgsplots_RadionM2500.root","READ")
histNew = fhiggs.Get("analyzerAK8Subjets/twoSubjetsHadronFlavourPT500")
histOld = fhiggs.Get("analyzerAK8Subjets/twoSubjetsPartonFlavourPT500")
histComp = fhiggs.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixRCPt50")
counter=0
for hist in (histNew,histOld,histComp):
	counter += 1
	hist.LabelsOption("a","X")
	hist.LabelsOption("a","Y")
	hist.GetXaxis().SetTitle("Leading Subjet Flavor")
	hist.GetYaxis().SetTitle("Second Leading Subjet Flavor")
	if (counter == 3):
		hist.SetTitle("H->bb Subjet Flavor Comparison")
	hist.Draw("colztext")
	tempstring = ""
	if (counter == 1):
		tempstring = "Hadron"
	elif (counter == 2):
		tempstring = "Parton"
	if (counter ==1 or counter ==2):
		c.SaveAs("SubjetFlavorComparison_"+tempstring+"_PT500.png")
	else:
		c.SaveAs("oldPartonNewHadronSubjetCompPT500.png")
	c.Clear()
histOldRel = histOld.Clone()
histNewRel = histNew.Clone()

for partonBin in (1,2,3,4):
    numMatchedToParton = histOld.Integral(partonBin,partonBin,1,4)
    for hadronBin in (1,2,3,4):
        initialContent = histOld.GetBinContent(partonBin,hadronBin)
        if(numMatchedToParton == 0):
        	newContent = 0;
        else:
        	newContent = float(initialContent)/float(numMatchedToParton);
        histOldRel.SetBinContent(partonBin,hadronBin,newContent)
#hist.GetXaxis().SetRangeUser(0,15);
#hist.GetYaxis().SetTitleOffset(1.4)
histOldRel.Draw("colztext")
c.SaveAs("SubjetFlavorComparison_Old_Rel_PT500.png")
c.Clear()
for partonBin in (1,2,3):
    numMatchedToParton = histNew.Integral(partonBin,partonBin,1,3)
    for hadronBin in (1,2,3):
        initialContent = histNew.GetBinContent(partonBin,hadronBin)
        if(numMatchedToParton == 0):
        	newContent = 0;
        else:
        	newContent = float(initialContent)/float(numMatchedToParton);
        histNewRel.SetBinContent(partonBin,hadronBin,newContent)
#hist.GetXaxis().SetRangeUser(0,15);
#hist.GetYaxis().SetTitleOffset(1.4)
histNewRel.Draw("colztext")
c.SaveAs("SubjetFlavorComparison_New_Rel_PT500.png")
c.Clear()

fhiggs1500 = TFile("higgsplots_RadionM1500.root","READ")
hist = fhiggs1500.Get("analyzerAK8/oldPartonNewHadronMatchMatrixRCPt30")
hist.SetTitle("Higgs Fat Jet Flavor Comparison")
hist.Draw("colztext")
c.SaveAs("oldPartonNewHadronFatCompPT300.png")
c.Clear()
hist = fhiggs1500.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixRCPt30")
hist.SetTitle("Higgs Subjet Flavor Comparison")
hist.Draw("colztext")
c.SaveAs("oldPartonNewHadronSubjetCompPT300.png")
c.Clear()

fileold=TFile("active_genjets_ttbar_plots.root","READ")
histRC=fileold.Get("analyzerAK5/matchMatrixpt20")
histRC.SetTitle("Ghost Hadron vs. Parton Flavor")
histRC.GetXaxis().SetTitle("Parton Flavor")
histRC.GetYaxis().SetTitle("Ghost Hadron Flavor")
histRC.Draw("colztext")
c.SaveAs("AK5MatchMatrixRC.png")
c.Clear()
histrel = histRC.Clone()
for partonBin in (1,2,3,4):
    numMatchedToParton = histRC.Integral(partonBin,partonBin,1,3)
    for hadronBin in (1,2,3):
        initialContent = histRC.GetBinContent(partonBin,hadronBin)
        newContent = float(initialContent)/float(numMatchedToParton);
        histrel.SetBinContent(partonBin,hadronBin,newContent)
#hist.GetXaxis().SetRangeUser(0,15);
#hist.GetYaxis().SetTitleOffset(1.4)
histrel.Draw("colztext")
c.SaveAs("AK5MatchMatrix.png")