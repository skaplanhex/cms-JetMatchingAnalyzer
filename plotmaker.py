from ROOT import *
#from numpy import *
gROOT.SetBatch(True) #no annoying popups --> fast running!
gStyle.SetOptStat(0)

file1000 = TFile("outfile1000_BINBYUNGROOMEDPT.root","READ")
file2500 = TFile("outfile2500_BINBYUNGROOMEDPT.root","READ")

h200 = file1000.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixPt20")
h200RC = file1000.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixRCPt20")

h300 = file1000.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixPt30")
h300RC = file1000.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixRCPt30")

h500 = file2500.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixPt50")
h500RC = file2500.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixRCPt50")

h1000 = file2500.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixPt100")
h1000RC = file2500.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixRCPt100")

c = TCanvas()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h200.Draw("colztext")
c.SaveAs("m1000pt200match.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h200RC.Draw("colztext")
c.SaveAs("m1000pt200matchRC.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h300.Draw("colztext")
c.SaveAs("m1000pt300match.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h300RC.Draw("colztext")
c.SaveAs("m1000pt300matchRC.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h500.Draw("colztext")
c.SaveAs("m2500pt500match.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h500RC.Draw("colztext")
c.SaveAs("m2500pt500matchRC.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h1000.Draw("colztext")
c.SaveAs("m2500pt1000match.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h1000RC.Draw("colztext")
c.SaveAs("m2500pt1000matchRC.png")
c.Clear()

comp300 = file1000.Get("analyzerAK8Subjets/twoSubjetsHadronFlavourPT300")
comp500 = file2500.Get("analyzerAK8Subjets/twoSubjetsHadronFlavourPT500")
comp1000 = file2500.Get("analyzerAK8Subjets/twoSubjetsHadronFlavourPT1000")

for hist in (comp300,comp500,comp1000):
    hist.LabelsOption("a","X")
    hist.LabelsOption("a","Y")
    hist.GetXaxis().SetTitle("Leading Subjet Ghost Hadron Flavor")
    hist.GetYaxis().SetTitle("Second Leading Subjet Ghost Hadron Flavor")
c.SetBorderMode(0)
c.SetFillColor(kWhite)
comp300.Draw("colztext")
c.SaveAs("m1000pt300subjetflavor.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
comp500.Draw("colztext")
c.SaveAs("m2500pt500subjetflavor.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
comp1000.Draw("colztext")
c.SaveAs("m2500pt1000subjetflavor.png")
c.Clear()

f = TFile("outfile1000.root","READ")
h300n = f.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixPt30")
h300RCn = f.Get("analyzerAK8Subjets/oldPartonNewHadronMatchMatrixRCPt30")

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h300n.Draw("colztext")
c.SaveAs("m1000pt300matchSUBPT.png")
c.Clear()

c.SetBorderMode(0)
c.SetFillColor(kWhite)
h300RCn.Draw("colztext")
c.SaveAs("m1000pt300matchRCSUBPT.png")
c.Clear()






# for mass in (1000,2500):
#     for pt in (20,30,50,100)
#     f = TFile('hbbplots_radionm'+mass+'.root')
#     c = TCanvas()




# for jetAlgo in ("AK5","KT6"):
#     f = TFile(clusterType+"_"+jetType+"_"+process+"_plots.root","READ")
#     c = TCanvas()
#     mmpt0_rc = f.Get('analyzer'+jetAlgo+'/newPartonNewHadronMatchMatrixRC')
#     mmpt20_rc = f.Get('analyzer'+jetAlgo+'/newPartonNewHadronMatchMatrixRCPt20')
#     mmpt50_rc = f.Get('analyzer'+jetAlgo+'/newPartonNewHadronMatchMatrixRCPt50')
#     drvspt = f.Get('analyzer'+jetAlgo+'/ghostHadronJetDr_JetPt')
#     bgptvsjetpt = f.Get('analyzer'+jetAlgo+'/bGhostPt_JetPt')
#     cgptvsjetpt = f.Get('analyzer'+jetAlgo+'/cGhostPt_JetPt')
#     cgptvsjetpt_cold = f.Get('analyzer'+jetAlgo+'/cGhostPt_JetPt_COld')
#     cgptvsjetpt_lightold = f.Get('analyzer'+jetAlgo+'/cGhostPt_JetPt_LightOld')
    
#     #deal with the match matrices first
#     counter = -1
#     for hist in (mmpt0_rc,mmpt20_rc,mmpt50_rc):
#         counter += 1
#         pt="0"
#         if(counter==0):
#             pt="pt0"
#         elif(counter==1):
#             pt="pt20"
#         elif(counter==2):
#             pt="pt50"
#         hist.GetXaxis().SetTitle("Parton Ghost Match Flavor")
#         hist.GetYaxis().SetTitle("Hadron Ghost Match Flavor")
#         hist2 = TH2D(hist)
#         hist.Draw("colztext")
#         c.SaveAs(clusterType+"_"+jetAlgo+jetType+"_"+process+"_"+pt+"_hadronghostpartonmatchmatrixRC.png")
#         c.Clear()
#         for partonBin in (1,2,3,4):
#             numMatchedToParton = hist2.Integral(partonBin,partonBin,1,3)
#             for hadronBin in (1,2,3):
#                 initialContent = hist2.GetBinContent(partonBin,hadronBin)
#                 newContent = float(initialContent)/float(numMatchedToParton);
#                 hist2.SetBinContent(partonBin,hadronBin,newContent)
#         hist2.Draw("colztext")
#         c.SaveAs(clusterType+"_"+jetAlgo+jetType+"_"+process+"_"+pt+"_hadronghostpartonmatchmatrix_partonnorm.png")
#         c.Clear()
#         hist3 = TH2D(hist)
#         for hadronBin in (1,2,3):
#             numMatchedToHadron = hist3.Integral(1,4,hadronBin,hadronBin)
#             for partonBin in (1,2,3,4):
#                 initialContent = hist3.GetBinContent(partonBin,hadronBin)
#                 newContent = float(initialContent)/float(numMatchedToHadron);
#                 hist3.SetBinContent(partonBin,hadronBin,newContent)
#         hist3.Draw("colztext")
#         c.SaveAs(clusterType+"_"+jetAlgo+jetType+"_"+process+"_"+pt+"_hadronghostpartonmatchmatrix_hadronnorm.png")
#         c.Clear()
        
        
        
        
        
#            #now deal with the hadron dR plot
#            meandrlist = []
#            rmslist = []
#            ptlist = []
#            for ptBin in range(1,drvspt.GetNbinsX()+1):
#                hproj = drvspt.ProjectionY("_py",ptBin,ptBin)
#                if (ptBin == 1 or ptBin == 2 or ptBin == 5 or ptBin == 10 or ptBin == 30 or ptBin==100):
#                    hproj.Draw()
#                    c.SaveAs(clusterType+"_"+jetAlgo+jetType+"_drjetptbin"+str(ptBin)+"PROJY.png")
#                    c.Clear()
#            if (ptBin % 10 == 0):
#                if(clusterType=="active" and jetType=="genjets" and jetAlgo=="AK5"):
#                #print hproj.GetMean(),ptBin-1
#                meandrlist.append(float(hproj.GetMean()))
#                ptlist.append(float(ptBin-1))
#                drvsptGraph = TGraph(len(meandrlist),array(ptlist),array(meandrlist))
#                drvsptGraph.SetTitle("Mean DR vs. PT")
#                drvsptGraph.Draw("AC*")
#                c.SaveAs(clusterType+"_"+jetAlgo+jetType+"_drjetclosestghostVSpt.png")
#                c.Clear()






#for genType in ('Pythia','Herwig'):
#    for dR in ('015','020','025','030','040','050'):
#        #for each type of jet
#        for jetType in ("GenJets","PFJets"):
#
#            f = TFile('matchMatrices_'+jetType+genType+'.root','READ')
#
#            hpt0 = f.Get('analyzerdR'+dR+'/matchMatrix')
#            hpt20 = f.Get('analyzerdR'+dR+'/matchMatrixpt20')
#            hpt30 = f.Get('analyzerdR'+dR+'/matchMatrixpt30')
#            hpt50 = f.Get('analyzerdR'+dR+'/matchMatrixpt50')
#            hpt100 = f.Get('analyzerdR'+dR+'/matchMatrixpt100')
#            counter=0
#            for hist in (hpt0, hpt20, hpt30, hpt50, hpt100):
#                hist.SetStats(0)
#                c=TCanvas()
#                pt=0
#                if counter == 0:
#                    pt=0
#                elif counter == 1:
#                    pt=20
#                elif counter == 2:
#                    pt=30
#                elif counter == 3:
#                    pt=50
#                elif counter == 4:
#                    pt=100
#                counter += 1
#                #same binning as in EDAnalyzer
#        #        hscaled = TH2D("matchMatrixScaled","Scaled Hadron vs. Parton Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5)
#                #for b, c, light, and no match
#                for partonBin in (1,2,3,4):
#        #            numMatchedToParton = 0
#        #            for i in (1,2,3):
#        #                numMatchedToParton += hist.GetBinContent(partonBin,i)
#                    numMatchedToParton = hist.Integral(partonBin,partonBin,1,3)
#                    for hadronBin in (1,2,3):
#                        initialContent = hist.GetBinContent(partonBin,hadronBin)
#                        newContent = float(initialContent)/float(numMatchedToParton);
#                        hist.SetBinContent(partonBin,hadronBin,newContent)
#        #            hproj = hist.ProjectionY("",partonBin,partonBin)
#        #            numMatchedToParton = hproj.Integral()
#        #            hproj.Scale(1./numMatchedToParton)
#                    #populate the scaled histogram
#        #            for ybin in (1,2,3):
#        #                hscaled.SetBinContent( partonBin, hproj.GetBinContent(ybin))
#                gROOT.SetStyle("Plain")
#                c.SetBorderMode(0)
#                c.SetFillColor(kWhite)
#                hist.Draw("colztext")
#                filename = 'matchMatrix_'+jetType+genType+'_pt'+str(pt)+'_dR'+dR+'.png'
#                c.SaveAs(filename)

