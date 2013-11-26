from ROOT import *
for genType in ('Pythia','Herwig'):
    for dR in ('015','020','025','030','040','050'):
        #for each type of jet
        for jetType in ("GenJets","PFJets"):
            
            f = TFile('matchMatrices_'+jetType+genType+'.root','READ')
            
            hpt0 = f.Get('analyzerdR'+dR+'/matchMatrix')
            hpt20 = f.Get('analyzerdR'+dR+'/matchMatrixpt20')
            hpt30 = f.Get('analyzerdR'+dR+'/matchMatrixpt30')
            hpt50 = f.Get('analyzerdR'+dR+'/matchMatrixpt50')
            hpt100 = f.Get('analyzerdR'+dR+'/matchMatrixpt100')
            counter=0
            for hist in (hpt0, hpt20, hpt30, hpt50, hpt100):
                hist.SetStats(0)
                c=TCanvas()
                pt=0
                if counter == 0:
                    pt=0
                elif counter == 1:
                    pt=20
                elif counter == 2:
                    pt=30
                elif counter == 3:
                    pt=50
                elif counter == 4:
                    pt=100
                counter += 1
                #same binning as in EDAnalyzer
        #        hscaled = TH2D("matchMatrixScaled","Scaled Hadron vs. Parton Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5)
                #for b, c, light, and no match
#                for partonBin in (1,2,3,4):
#        #            numMatchedToParton = 0
#        #            for i in (1,2,3):
#        #                numMatchedToParton += hist.GetBinContent(partonBin,i)
#                    numMatchedToParton = hist.Integral(partonBin,partonBin,1,3)
#                    for hadronBin in (1,2,3):
#                        initialContent = hist.GetBinContent(partonBin,hadronBin)
#                        newContent = float(initialContent)/float(numMatchedToParton);
#                        hist.SetBinContent(partonBin,hadronBin,newContent)
        #            hproj = hist.ProjectionY("",partonBin,partonBin)
        #            numMatchedToParton = hproj.Integral()
        #            hproj.Scale(1./numMatchedToParton)
                    #populate the scaled histogram
        #            for ybin in (1,2,3):
        #                hscaled.SetBinContent( partonBin, hproj.GetBinContent(ybin))
                gROOT.SetStyle("Plain")
                c.SetBorderMode(0)
                c.SetFillColor(kWhite)
                hist.Draw("colztext")
                filename = 'RAWCOUNTmatchMatrix_'+jetType+genType+'_pt'+str(pt)+'_dR'+dR+'.png'
                c.SaveAs(filename)

