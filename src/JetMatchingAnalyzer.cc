// -*- C++ -*-
//
// Package:    JetMatchingAnalyzer
// Class:      JetMatchingAnalyzer
//
/**\class JetMatchingAnalyzer JetMatchingAnalyzer.cc Analyzers/JetMatchingAnalyzer/src/JetMatchingAnalyzer.cc
 
 Description: [one line class summary]
 
 Implementation:
 [Notes on implementation]
 */
//
// Original Author:  Steven Mitchell Kaplan,,,
//         Created:  Mon Sep 23 20:42:38 CEST 2013
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/View.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/getRef.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/JetCollection.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/JetFloatAssociation.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "SimDataFormats/JetMatching/interface/JetFlavour.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourMatching.h"
#include "SimDataFormats/JetMatching/interface/MatchedPartons.h"
#include "SimDataFormats/JetMatching/interface/JetMatchedPartons.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourInfo.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourInfoMatching.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

//GenParticleCollection
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"

#include "TH2D.h"
#include "TH3D.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace edm;
using namespace std;
//
// class declaration
//

class JetMatchingAnalyzer : public edm::EDAnalyzer {
public:
    explicit JetMatchingAnalyzer(const edm::ParameterSet&);
    ~JetMatchingAnalyzer();
    
    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
    
    
private:
    virtual void beginJob() ;
    virtual void analyze(const edm::Event&, const edm::EventSetup&);
    virtual void endJob() ;
    
    virtual void beginRun(edm::Run const&, edm::EventSetup const&);
    virtual void endRun(edm::Run const&, edm::EventSetup const&);
    virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
    virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
    virtual double DeltaR_Rapidity(const reco::Candidate* const cand1, const reco::Candidate* const cand2);
    // ----------member data ---------------------------
    edm::Service<TFileService> fs;
    edm::InputTag particleSrc, partonFlavourByRefSrc, jetFlavourInfos_;
    edm::Handle< reco::GenParticleCollection > particles;
    edm::Handle<reco::JetFlavourInfoMatchingCollection> theJetFlavourInfos;
    edm::Handle< reco::JetMatchedPartonsCollection > jetFlavourByRefMatches;
    double hadronMatchDr;
    double jetPtCut;
    TH2D* oldPartonNewHadronMatchMatrixRC;
    TH2D* oldPartonNewHadronMatchMatrixRCPt20;
    TH2D* oldPartonNewHadronMatchMatrixRCPt30;
    TH2D* oldPartonNewHadronMatchMatrixRCPt50;
    TH2D* oldPartonNewHadronMatchMatrixRCPt100;
    
    TH2D* oldPartonNewHadronMatchMatrix;
    TH2D* oldPartonNewHadronMatchMatrixPt20;
    TH2D* oldPartonNewHadronMatchMatrixPt30;
    TH2D* oldPartonNewHadronMatchMatrixPt50;
    TH2D* oldPartonNewHadronMatchMatrixPt100;
    
    TH2D* newPartonNewHadronMatchMatrixRC;
    TH2D* newPartonNewHadronMatchMatrixRCPt20;
    TH2D* newPartonNewHadronMatchMatrixRCPt30;
    TH2D* newPartonNewHadronMatchMatrixRCPt50;
    TH2D* newPartonNewHadronMatchMatrixRCPt100;
    
    TH2D* newPartonNewHadronMatchMatrixHadronNorm;
    TH2D* newPartonNewHadronMatchMatrixHadronNormPt20;
    TH2D* newPartonNewHadronMatchMatrixHadronNormPt30;
    TH2D* newPartonNewHadronMatchMatrixHadronNormPt50;
    TH2D* newPartonNewHadronMatchMatrixHadronNormPt100;
    
    TH2D* newPartonNewHadronMatchMatrixPartonNorm;
    TH2D* newPartonNewHadronMatchMatrixPartonNormPt20;
    TH2D* newPartonNewHadronMatchMatrixPartonNormPt30;
    TH2D* newPartonNewHadronMatchMatrixPartonNormPt50;
    TH2D* newPartonNewHadronMatchMatrixPartonNormPt100;
    
    
    TH2D* ghostHadronJetDr_JetPt;
    TH2D* bGhostPt_JetPt;
    TH2D* cGhostPt_JetPt;
    TH2D* cGhostPt_JetPt_COld;
    TH2D* cGhostPt_JetPt_LightOld;
    TH1D* hJetConstituentNum;
    TH1D* hJetConstituentType;
    TH1D* hJetEta;
    TH1D* hJetPt;
    TH1D* hJetPhi;
    TH1D* hJetNum;
    TH1D* hJetConstituentNumALL;
    TH1D* hJetConstituentTypeALL;
    TH1D* hJetEtaALL;
    TH1D* hJetPtALL;
    TH1D* hJetPhiALL;
    
    //ofstreams to make text files of events in each category
    ofstream eventJSON;
    ofstream eventINFO;
     
     /*ofstream bparton_chadron_eventINFO;
     ofstream bparton_chadron_eventJSON;
     ofstream bparton_lighthadron_eventINFO;
     ofstream bparton_lighthadron_eventJSON;
     
     ofstream cparton_bhadron_eventINFO;
     ofstream cparton_bhadron_eventJSON;
     ofstream cparton_lighthadron_eventINFO;
     ofstream cparton_lighthadron_eventJSON;
     
     ofstream lightparton_bhadron_eventINFO;
     ofstream lightparton_bhadron_eventJSON;
     ofstream lightparton_chadron_eventINFO;
     ofstream lightparton_chadron_eventJSON;*/
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
JetMatchingAnalyzer::JetMatchingAnalyzer(const edm::ParameterSet& iConfig)

{
    //get the parameters given in the config file
    particleSrc = iConfig.getParameter<InputTag>("particleSource");
    jetFlavourInfos_ = iConfig.getParameter<edm::InputTag> ("jetFlavourInfos");
    partonFlavourByRefSrc = iConfig.getParameter<InputTag>("srcByRef");
    hadronMatchDr = iConfig.getParameter<double>("hadronMatchDr");
    jetPtCut = iConfig.getParameter<double>("jetPtCut");
    
    //initialize filenames for each ofstream
    eventJSON.open("eventJSON.txt");
    eventINFO.open("eventINFO.txt");
     /*bparton_chadron_eventINFO.open("bparton_chadron_eventINFO.txt");
     bparton_chadron_eventJSON.open("bparton_chadron_eventJSON.txt");
     bparton_lighthadron_eventINFO.open("bparton_lighthadron_eventINFO.txt");
     bparton_lighthadron_eventJSON.open("bparton_lighthadron_eventJSON.txt");
     
     cparton_bhadron_eventINFO.open("cparton_bhadron_eventINFO.txt");
     cparton_bhadron_eventJSON.open("cparton_bhadron_eventJSON.txt");
     cparton_lighthadron_eventINFO.open("cparton_lighthadron_eventINFO.txt");
     cparton_lighthadron_eventJSON.open("cparton_lighthadron_eventJSON.txt");
     
     lightparton_bhadron_eventINFO.open("lightparton_bhadron_eventINFO.txt");
     lightparton_bhadron_eventJSON.open("lightparton_bhadron_eventJSON.txt");
     lightparton_chadron_eventINFO.open("lightparton_chadron_eventINFO.txt");
     lightparton_chadron_eventJSON.open("lightparton_chadron_eventJSON.txt"); */
}


JetMatchingAnalyzer::~JetMatchingAnalyzer()
{
    
    // do anything here that needs to be done at desctruction time
    // (e.g. close files, deallocate resources etc.)
    
    //once all the events are processed, close filestreams
    eventJSON.close();
    eventINFO.close();
     /*bparton_chadron_eventINFO.close();
     bparton_chadron_eventJSON.close();
     bparton_lighthadron_eventINFO.close();
     bparton_lighthadron_eventJSON.close();
     
     cparton_bhadron_eventINFO.close();
     cparton_bhadron_eventJSON.close();
     cparton_lighthadron_eventINFO.close();
     cparton_lighthadron_eventJSON.close();
     
     lightparton_bhadron_eventINFO.close();
     lightparton_bhadron_eventJSON.close();
     lightparton_chadron_eventINFO.close();
     lightparton_chadron_eventJSON.close(); */
    
}


//
// member functions
//
double
JetMatchingAnalyzer::DeltaR_Rapidity(const reco::Candidate* const cand1, const reco::Candidate* const cand2)
{
    double p1 = cand1->phi();
    double p2 = cand2->phi();
    double r1 = cand1->rapidity();
    double r2 = cand2->rapidity();
    double dp = reco::deltaPhi(p1,p2);
    return std::sqrt((r1-r2)*(r1-r2)+dp*dp);
    
}

// ------------ method called for each event  ------------
void
JetMatchingAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace std;
        unsigned int lumi = iEvent.luminosityBlock();
        unsigned int run = iEvent.run();
        unsigned int event = iEvent.id().event();
    
        stringstream ss;
        ss << run << ":" << lumi << ":" << event;
        string eventAddress = ss.str();
        bool eventAdded = false;
    
    
    //    cout << eventAddress << endl;
    //    cout << "run: " << run << endl;
    //    cout << "lumisection: " << lumi << endl;
    //    cout << "event: " << event << endl;
    //    myFile << eventAddress;
    
    
    iEvent.getByLabel(particleSrc,particles);
    iEvent.getByLabel(partonFlavourByRefSrc,jetFlavourByRefMatches);
    iEvent.getByLabel(jetFlavourInfos_ , theJetFlavourInfos );
    
    for (reco::JetFlavourInfoMatchingCollection::const_iterator iMatch = theJetFlavourInfos->begin(); iMatch != theJetFlavourInfos->end(); ++iMatch) {
        
        int currentIndex = iMatch - theJetFlavourInfos->begin();
        
        const reco::Jet* iJet  = (*iMatch).first.get();
        const reco::JetFlavourInfo aInfo = (*iMatch).second;
        const reco::GenParticleRefVector & bHadrons = aInfo.getbHadrons();
        const reco::GenParticleRefVector & cHadrons = aInfo.getcHadrons();
        const reco::GenParticleRefVector & partons = aInfo.getPartons();
        bool matchedtoGhostHadron = (bHadrons.size() != 0) || (cHadrons.size() != 0);
        const reco::GenParticleRef partonRef = (*jetFlavourByRefMatches)[currentIndex].second.algoDefinitionParton();
        math::XYZTLorentzVector jetp4 = iJet->p4();
        double jetEt = iJet->et();
        double jetPt = iJet->pt();
        double jetRapidity = iJet->rapidity();
        double jetEta = iJet->eta();
        double jetPhi = iJet->phi();
        
        //loop through b and c hadron ghost matches to get the dR between the jet and the closest ghost
        reco::GenParticle* closestGhostHadron = NULL;
        double closestGhostHadronDr = 10000;
        for(reco::GenParticleRefVector::const_iterator it = bHadrons.begin(); it != bHadrons.end(); ++it){
            const reco::GenParticle* hadron = &(*(*it));
            double dr = DeltaR_Rapidity(iJet,hadron);
            if (dr < closestGhostHadronDr) {
                closestGhostHadronDr = dr;
                closestGhostHadron = const_cast< reco::GenParticle* >(hadron);
            }
        }
        for(reco::GenParticleRefVector::const_iterator it = cHadrons.begin(); it != cHadrons.end(); ++it){
            const reco::GenParticle* hadron = &(*(*it));
            double dr = DeltaR_Rapidity(iJet,hadron);
            if (dr < closestGhostHadronDr) {
                closestGhostHadronDr = dr;
                closestGhostHadron = const_cast< reco::GenParticle* >(hadron);
            }
        }
        if (matchedtoGhostHadron) {
            //cout << matchedtoGhostHadron << " " << jetPt << " " << closestGhostHadronDr << endl;
            ghostHadronJetDr_JetPt->Fill(jetPt,closestGhostHadronDr);
        }
        //loop over parton ghost matches to get the dR between the jet and the closest parton ghost
        reco::GenParticle* closestGhostParton = NULL;
        double closestGhostPartonDr = 10000;
        for(reco::GenParticleRefVector::const_iterator it = partons.begin(); it != partons.end(); ++it){
            const reco::GenParticle* parton = &(*(*it));
            double dr = DeltaR_Rapidity(iJet,parton);
            if (dr < closestGhostPartonDr) {
                closestGhostPartonDr = dr;
                closestGhostParton = const_cast< reco::GenParticle* >(parton);
            }
        }
        //old parton matching
        bool matchedtoBQuark;
        bool matchedtoCQuark;
        bool matchedtoLightFlavor;
        bool notMatchedToParton;
        
        if (partonRef.isNull()) { //if there is no matched parton
            matchedtoBQuark = false;
            matchedtoCQuark = false;
            matchedtoLightFlavor = false;
            notMatchedToParton = true;
        }
        else {
            const reco::Candidate* parton = partonRef.get();
            const int iPartonFlav = parton->pdgId();
            matchedtoBQuark = (abs(iPartonFlav) == 5);
            matchedtoCQuark = (abs(iPartonFlav) == 4);
            matchedtoLightFlavor = ((abs(iPartonFlav) == 1) || (abs(iPartonFlav) == 2) || (abs(iPartonFlav) == 3) || iPartonFlav == 21);
            //if not matched to b, c, or light parton
            notMatchedToParton = (!matchedtoBQuark) && (!matchedtoCQuark) && (!matchedtoLightFlavor);
        }
        
        //ghost matching
        bool matchedtoBHadronGhost = false;
        bool matchedtoCHadronGhost = false;
        bool matchedtoLightHadronGhost = true;
        
        bool matchedtoBPartonGhost = false;
        bool matchedtoCPartonGhost = false;
        bool matchedtoLightPartonGhost = false;
        bool notMatchedToPartonGhost = false;
        
        int partonGhostFlavour = aInfo.getPartonFlavour();
        int hadronGhostFlavour = aInfo.getHadronFlavour();
        
        //fill booleans for parton ghosts
        if (partonGhostFlavour == 4)
            matchedtoCPartonGhost = true;
        else if (partonGhostFlavour == 5)
            matchedtoBPartonGhost = true;
        else if (partonGhostFlavour == 1 || partonGhostFlavour == 2 || partonGhostFlavour == 3 || partonGhostFlavour == 21)
            matchedtoLightPartonGhost = true;
        else
            notMatchedToPartonGhost = true;
        
        //fill booleans for hadron ghosts.  If flavour isn't 4 or 5, it's zero, so keep default booleans
        if (hadronGhostFlavour == 4) {
            matchedtoCHadronGhost = true;
            matchedtoLightHadronGhost = false;
        }
        else if (hadronGhostFlavour == 5){
            matchedtoBHadronGhost = true;
            matchedtoLightHadronGhost = false;
        }
        
        //do the dr based hadron matching.  If there is a b or c hadron within a cone of hadronMatchDr, the jet is associated to that hadron
        bool matchedtoBHadron = false; //for now
        bool matchedtoCHadron = false; //for now
        bool matchedtoLightHadron = true; //for now.  We assume the jet is a light jet unless matched otherwise.  If otherwise matched, this will be set to false.
        double jetBHadronDr = 10000.; //dr between jet and closest b hadron
        double jetCHadronDr = 10000.; //dr between jet and closest c hadron
        double jetCQuarkDr = 10000.;
        reco::GenParticle* closestBHadron = NULL;
        reco::GenParticle* closestCHadron = NULL;
        reco::GenParticle* closestCQuark = NULL;
        for (reco::GenParticleCollection::const_iterator iGenPart = particles->begin(); iGenPart != particles->end(); ++iGenPart) {
            double jetHadronDr = reco::deltaR(jetp4, iGenPart->p4());
            int absPartID = abs(iGenPart->pdgId());
            // if the gen particle is a b hadron
            if (((absPartID/100)%10 == 5 || (absPartID/1000)%10 == 5)) {
                if (jetHadronDr < hadronMatchDr){
                    matchedtoBHadron = true;
                    matchedtoLightHadron = false; //if matched to a b, it obviously isn't matched to light
                }
                if (jetHadronDr < jetBHadronDr) {
                    closestBHadron = const_cast< reco::GenParticle* >(&(*iGenPart));
                    //cout << "b hadron dr: " << jetHadronDr << endl;
                    jetBHadronDr = jetHadronDr;
                }
            }
            // if the gen particle is a c hadron
            else if ( ((absPartID/100)%10 == 4 || (absPartID/1000)%10 == 4) ) {
                if (jetHadronDr < hadronMatchDr){
                    matchedtoCHadron = true;
                    matchedtoLightHadron = false;
                }
                if (jetHadronDr < jetCHadronDr) {
                    closestCHadron = const_cast< reco::GenParticle* >(&(*iGenPart));
                    //                    cout << "c hadron dr: " << jetHadronDr << endl;
                    jetCHadronDr = jetHadronDr;
                }
            }
            else if (absPartID == 4){
                if (jetHadronDr < jetCQuarkDr) {
                    closestCQuark = const_cast< reco::GenParticle* >(&(*iGenPart));
                    jetCQuarkDr = jetHadronDr;
                }
            }
        } //end loop over genParticles
        
        if (matchedtoBHadronGhost && closestBHadron) {
            bGhostPt_JetPt->Fill(jetPt,closestBHadron->pt());
        }
        else if (matchedtoCHadronGhost && closestCHadron) {
            cGhostPt_JetPt->Fill(jetPt,closestCHadron->pt());
        }
        if (matchedtoCHadronGhost && closestCHadron && matchedtoCQuark) {
            cGhostPt_JetPt_COld->Fill(jetPt,closestCHadron->pt());
        }
        else if (matchedtoCHadronGhost && closestCHadron && matchedtoLightFlavor){
            cGhostPt_JetPt_LightOld->Fill(jetPt,closestCHadron->pt());
        }
        
        
        
        
        
        //first fill histograms for all jets, then fill for jets who fail parton matching
        std::vector< const reco::Candidate* > jetConstituents = iJet->getJetConstituentsQuick();
        for (unsigned int i=0; i<jetConstituents.size(); i++) {
            hJetConstituentTypeALL->Fill( jetConstituents[i]->pdgId() );
        }
        hJetEtaALL->Fill(jetEta);
        hJetPtALL->Fill(jetPt);
        hJetPhiALL->Fill(jetPhi);
        hJetConstituentNumALL->Fill( iJet->nConstituents() );
        
        //for all combinations, choose bins to fill in the match matrix depending on the case
        
        // convention for partonNum and ghostHadronNum:
        // b flavor := 0
        // c flavor := 1
        // light flavor := 2
        // flavor failure := 3 (only valid for partons, all jets not clustered with b or c hadrons are assumed to be light)
        
        int partonNum = -100;
        int ghostHadronNum = -100;
        
        if (matchedtoBQuark && matchedtoBHadronGhost) {
            partonNum = 0;
            ghostHadronNum = 0;
        }
        else if (matchedtoBQuark && matchedtoCHadronGhost){
            partonNum = 0;
            ghostHadronNum = 1;
        }
        else if (matchedtoBQuark && matchedtoLightHadronGhost) {
            partonNum = 0;
            ghostHadronNum = 2;
        }
        else if (matchedtoCQuark && matchedtoBHadronGhost) {
            partonNum = 1;
            ghostHadronNum = 0;
        }
        else if (matchedtoCQuark && matchedtoCHadronGhost){
            partonNum = 1;
            ghostHadronNum = 1;
        }
        else if (matchedtoCQuark && matchedtoLightHadronGhost) {
            partonNum = 1;
            ghostHadronNum = 2;
        }
        else if (matchedtoLightFlavor && matchedtoBHadronGhost) {
            partonNum = 2;
            ghostHadronNum = 0;
        }
        else if (matchedtoLightFlavor && matchedtoCHadronGhost){
            partonNum = 2;
            ghostHadronNum = 1;
        }
        else if (matchedtoLightFlavor && matchedtoLightHadronGhost) {
            partonNum = 2;
            ghostHadronNum = 2;
        }
        else if (notMatchedToParton && matchedtoBHadronGhost) {
            partonNum = 3;
            ghostHadronNum = 0;
        }
        else if (notMatchedToParton && matchedtoCHadronGhost){
            partonNum = 3;
            ghostHadronNum = 1;
        }
        else if (notMatchedToParton && matchedtoLightHadronGhost) {
            partonNum = 3;
            ghostHadronNum = 2;
        }
        
        if (fabs(jetEta) < 2.5) {
            //fill matrix without pt cut for comparison
            oldPartonNewHadronMatchMatrixRC->Fill(partonNum,ghostHadronNum);
            
            //fill matrices based on pt cut
            if (jetPt > 100) {
                oldPartonNewHadronMatchMatrixRCPt100->Fill(partonNum,ghostHadronNum);
            }
            if (jetPt > 50) {
                oldPartonNewHadronMatchMatrixRCPt50->Fill(partonNum,ghostHadronNum);
            }
            if (jetPt > 30) {
                oldPartonNewHadronMatchMatrixRCPt30->Fill(partonNum,ghostHadronNum);
            }
            if (jetPt > 20) {
                oldPartonNewHadronMatchMatrixRCPt20->Fill(partonNum,ghostHadronNum);
            }
        }//end eta if statement
        
        // parton ghost hadron ghost comparison
        int partonGhostNum = -100;
        ghostHadronNum = -100;
        
        if (matchedtoBQuark && matchedtoBHadronGhost) {
            partonGhostNum = 0;
            ghostHadronNum = 0;
        }
        else if (matchedtoBPartonGhost && matchedtoCHadronGhost){
            partonGhostNum = 0;
            ghostHadronNum = 1;
        }
        else if (matchedtoBPartonGhost && matchedtoLightHadronGhost) {
            partonGhostNum = 0;
            ghostHadronNum = 2;
        }
        else if (matchedtoBPartonGhost && matchedtoBHadronGhost) {
            partonGhostNum = 1;
            ghostHadronNum = 0;
        }
        else if (matchedtoCPartonGhost && matchedtoCHadronGhost){
            partonGhostNum = 1;
            ghostHadronNum = 1;
        }
        else if (matchedtoCPartonGhost && matchedtoLightHadronGhost) {
            partonGhostNum = 1;
            ghostHadronNum = 2;
            //these are events where a jet was matched to a c parton ghost but NOT a c (or a b) hadron ghost.  Why?
            //Find out the dR between the jet and the closest c hadron, print that and the dR between the jet and the closest c a
            //write the events and relevant info to the text files
            if (!eventAdded && jetPt > 50) {
                eventJSON << eventAddress << "\n";
                eventINFO << eventAddress << "\n";
                eventINFO << "\n";
                eventINFO << "Jet ET: " << jetEt << "\n";
                eventINFO << "Jet Eta: " << jetEta << "\n";
                eventINFO << "Jet Phi: " << jetPhi << "\n";
                eventINFO << "Jet Rapidity: " << jetRapidity << "\n";
                if (closestGhostParton) {
                    eventINFO << "pdgid of closest ghost parton: " << closestGhostParton->pdgId() << "\n";
                    eventINFO << "dR between closest ghost parton and jet: " << closestGhostPartonDr << "\n";
                }
                else{
                    eventINFO << "No matched ghost partons...um...why? Should be matched to a C; INVESTIGATE!" << "\n";
                }
                if (closestCHadron) {
                    eventINFO << "pT of closest C Hadron: " << closestCHadron->pt() << "\n";
                    eventINFO << "Eta of closest C Hadron: " << closestCHadron->eta() << "\n";
                    eventINFO << "Phi of closest C Hadron: " << closestCHadron->phi() << "\n";
                    double chadjetdrrap = DeltaR_Rapidity(iJet,const_cast<reco::GenParticle*>(closestCHadron));
                    eventINFO << "DR (rapidity) between closest C Hadron and Jet: " << chadjetdrrap << "\n";
                }
                else{
                    eventINFO << "NO C HADRON IN THE EVENT!!!" << "\n";
                }
                eventINFO << "--------------------------" << "\n" << "\n";
                eventAdded = true;
            }
        }
        else if (matchedtoLightPartonGhost && matchedtoBHadronGhost) {
            partonGhostNum = 2;
            ghostHadronNum = 0;
        }
        else if (matchedtoLightPartonGhost && matchedtoCHadronGhost){
            partonGhostNum = 2;
            ghostHadronNum = 1;
        }
        else if (matchedtoLightPartonGhost && matchedtoLightHadronGhost) {
            partonGhostNum = 2;
            ghostHadronNum = 2;
        }
        else if (notMatchedToPartonGhost && matchedtoBHadronGhost) {
            partonGhostNum = 3;
            ghostHadronNum = 0;
        }
        else if (notMatchedToPartonGhost && matchedtoCHadronGhost){
            partonGhostNum = 3;
            ghostHadronNum = 1;
        }
        else if (notMatchedToPartonGhost && matchedtoLightHadronGhost) {
            partonGhostNum = 3;
            ghostHadronNum = 2;
        }
        if (fabs(jetEta) < 2.5) {
            //fill matrix without pt cut for comparison
            newPartonNewHadronMatchMatrixRC->Fill(partonGhostNum,ghostHadronNum);
            
            //fill matrices based on pt cut
            if (jetPt > 100) {
                newPartonNewHadronMatchMatrixRCPt100->Fill(partonGhostNum,ghostHadronNum);
            }
            if (jetPt > 50) {
                newPartonNewHadronMatchMatrixRCPt50->Fill(partonGhostNum,ghostHadronNum);
            }
            if (jetPt > 30) {
                newPartonNewHadronMatchMatrixRCPt30->Fill(partonGhostNum,ghostHadronNum);
            }
            if (jetPt > 20) {
                newPartonNewHadronMatchMatrixRCPt20->Fill(partonGhostNum,ghostHadronNum);
            }
        }//end eta if statement
    } //end loop over jet matches
    
}


// ------------ method called once each job just before starting event loop  ------------
void
JetMatchingAnalyzer::beginJob()
{
    oldPartonNewHadronMatchMatrixRC = fs->make<TH2D>("oldPartonNewHadronMatchMatrixRC","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
    //change bin labels to alphanumeric
    oldPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(1,"b");
    oldPartonNewHadronMatchMatrixRC->GetYaxis()->SetBinLabel(1,"b");
    oldPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(2,"c");
    oldPartonNewHadronMatchMatrixRC->GetYaxis()->SetBinLabel(2,"c");
    oldPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(3,"light");
    oldPartonNewHadronMatchMatrixRC->GetYaxis()->SetBinLabel(3,"light");
    oldPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(4,"no match");
    
    oldPartonNewHadronMatchMatrixRC->GetXaxis()->SetTitle("Parton Match Flavor");
    oldPartonNewHadronMatchMatrixRC->GetYaxis()->SetTitle("Hadron Ghost Match Flavor");
    
    //use copy constructor to copy pt0 histogram for others after implementing the proper labelling
    oldPartonNewHadronMatchMatrixRCPt20 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRC ) ));
    oldPartonNewHadronMatchMatrixRCPt30 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRC ) ));
    oldPartonNewHadronMatchMatrixRCPt50 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRC ) ));
    oldPartonNewHadronMatchMatrixRCPt100 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRC ) ));
    
    //distinguish the histograms by the names! (old name is copied to each)
    oldPartonNewHadronMatchMatrixRCPt20->SetName("oldPartonNewHadronMatchMatrixRCPt20");
    oldPartonNewHadronMatchMatrixRCPt30->SetName("oldPartonNewHadronMatchMatrixRCPt30");
    oldPartonNewHadronMatchMatrixRCPt50->SetName("oldPartonNewHadronMatchMatrixRCPt50");
    oldPartonNewHadronMatchMatrixRCPt100->SetName("oldPartonNewHadronMatchMatrixRCPt100");
    
    //oldPartonNewHadronMatchMatrixRCPt20 = fs->make<TH2D>("oldPartonNewHadronMatchMatrixRCPt20","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
    //oldPartonNewHadronMatchMatrixRCPt30 = fs->make<TH2D>("oldPartonNewHadronMatchMatrixRCPt30","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
    //oldPartonNewHadronMatchMatrixRCPt50 = fs->make<TH2D>("oldPartonNewHadronMatchMatrixRCPt50","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
    //oldPartonNewHadronMatchMatrixRCPt100 = fs->make<TH2D>("oldPartonNewHadronMatchMatrixRCPt100","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
    
    newPartonNewHadronMatchMatrixRC = fs->make<TH2D>("newPartonNewHadronMatchMatrixRC","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
    
    newPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(1,"b");
    newPartonNewHadronMatchMatrixRC->GetYaxis()->SetBinLabel(1,"b");
    newPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(2,"c");
    newPartonNewHadronMatchMatrixRC->GetYaxis()->SetBinLabel(2,"c");
    newPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(3,"light");
    newPartonNewHadronMatchMatrixRC->GetYaxis()->SetBinLabel(3,"light");
    newPartonNewHadronMatchMatrixRC->GetXaxis()->SetBinLabel(4,"no match");
    
    newPartonNewHadronMatchMatrixRC->GetXaxis()->SetTitle("Parton Ghost Match Flavor");
    newPartonNewHadronMatchMatrixRC->GetYaxis()->SetTitle("Hadron Ghost Match Flavor");
    
    newPartonNewHadronMatchMatrixRCPt20 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRC ) ));
    newPartonNewHadronMatchMatrixRCPt30 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRC ) ));
    newPartonNewHadronMatchMatrixRCPt50 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRC ) ));
    newPartonNewHadronMatchMatrixRCPt100 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRC ) ));
    
    newPartonNewHadronMatchMatrixRCPt20->SetName("newPartonNewHadronMatchMatrixRCPt20");
    newPartonNewHadronMatchMatrixRCPt30->SetName("newPartonNewHadronMatchMatrixRCPt30");
    newPartonNewHadronMatchMatrixRCPt50->SetName("newPartonNewHadronMatchMatrixRCPt50");
    newPartonNewHadronMatchMatrixRCPt100->SetName("newPartonNewHadronMatchMatrixRCPt100");
    
    
    
//    newPartonNewHadronMatchMatrixRCPt20 = fs->make<TH2D>("newPartonNewHadronMatchMatrixRCPt20","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
//    newPartonNewHadronMatchMatrixRCPt30 = fs->make<TH2D>("newPartonNewHadronMatchMatrixRCPt30","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
//    newPartonNewHadronMatchMatrixRCPt50 = fs->make<TH2D>("newPartonNewHadronMatchMatrixRCPt50","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
//    newPartonNewHadronMatchMatrixRCPt100 = fs->make<TH2D>("newPartonNewHadronMatchMatrixRCPt100","Flavor Tag Correlation Matrix", 4,-0.5,3.5,3,-0.5,2.5);
    
    
    
    hJetConstituentNumALL = fs->make<TH1D>("hJetConstituentNumALL", "Jet Constituent Multiplicity",101,-0.5,100.5);
    hJetConstituentTypeALL = fs->make<TH1D>("hJetConstituentTypeALL", "Jet Constituent PDGID",5601,-0.5,5600.5);
    hJetEtaALL = fs->make<TH1D>("hJetEtaALL", "Jet Eta",100,-7,7);
    hJetPhiALL = fs->make<TH1D>("hJetPhiALL", "Jet Phi",100,0,3.14159);
    hJetPtALL = fs->make<TH1D>("hJetPtALL", "Jet Pt",600,0,600);
    hJetConstituentNum = fs->make<TH1D>("hJetConstituentNum", "Unmatched Jet Constituent Multiplicity",101,-0.5,100.5);
    hJetConstituentType = fs->make<TH1D>("hJetConstituentType", "Unmatched Jet Constituent PDGID",5601,-0.5,5600.5);
    hJetEta = fs->make<TH1D>("hJetEta", "Unmatched Jet Eta",100,-7,7);
    hJetPhi = fs->make<TH1D>("hJetPhi", "Unmatched Jet Phi",100,0,3.14159);
    hJetPt = fs->make<TH1D>("hJetPt", "Unmatched Jet Pt",600,0,600);
    hJetNum = fs->make<TH1D>("hJetNum", "Jet Multiplicity",61,-0.5,60.5);
    ghostHadronJetDr_JetPt = fs->make<TH2D>("ghostHadronJetDr_JetPt","dR Between Jet and Closest Hadron Match VS Jet pT",500,0,500,150,0,1.5);
    bGhostPt_JetPt = fs->make<TH2D>("bGhostPt_JetPt","B Ghost Hadron pT VS Jet pT",500,0,500,500,0,500);
    cGhostPt_JetPt = fs->make<TH2D>("cGhostPt_JetPt","C Ghost Hadron pT VS Jet pT",500,0,500,500,0,500);
    cGhostPt_JetPt_COld = fs->make<TH2D>("cGhostPt_JetPt_COld","C Ghost Hadron pT VS Jet pT (matched to c with old tool)",500,0,500,500,0,500);
    cGhostPt_JetPt_LightOld = fs->make<TH2D>("cGhostPt_JetPt_LightOld","C Ghost Hadron pT VS Jet pT (matched to light flavor with old tool)",500,0,500,500,0,500);
}

// ------------ method called once each job just after ending the event loop  ------------
void
JetMatchingAnalyzer::endJob()
{
    oldPartonNewHadronMatchMatrix = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRC ) ));
    oldPartonNewHadronMatchMatrixPt20 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt20 ) ));
    oldPartonNewHadronMatchMatrixPt30 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt30 ) ));
    oldPartonNewHadronMatchMatrixPt50 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt50 ) ));
    oldPartonNewHadronMatchMatrixPt100 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt100 ) ));
    
    oldPartonNewHadronMatchMatrix->SetName("oldPartonNewHadronMatchMatrix"); cout << "Issue 0" << endl;
    oldPartonNewHadronMatchMatrixPt20->SetName("oldPartonNewHadronMatchMatrixPt20");
    oldPartonNewHadronMatchMatrixPt30->SetName("oldPartonNewHadronMatchMatrixPt30");
    oldPartonNewHadronMatchMatrixPt50->SetName("oldPartonNewHadronMatchMatrixPt50");
    oldPartonNewHadronMatchMatrixPt100->SetName("oldPartonNewHadronMatchMatrixPt100");
    
    newPartonNewHadronMatchMatrixHadronNorm = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRC ) ));
    newPartonNewHadronMatchMatrixHadronNormPt20 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt20 ) ));
    newPartonNewHadronMatchMatrixHadronNormPt30 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt30 ) ));
    newPartonNewHadronMatchMatrixHadronNormPt50 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt50 ) ));
    newPartonNewHadronMatchMatrixHadronNormPt100 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt100 ) ));
    
    newPartonNewHadronMatchMatrixHadronNorm->SetName("newPartonNewHadronMatchMatrixHadronNorm");
    newPartonNewHadronMatchMatrixHadronNormPt20->SetName("newPartonNewHadronMatchMatrixHadronNormPt20");
    newPartonNewHadronMatchMatrixHadronNormPt30->SetName("newPartonNewHadronMatchMatrixHadronNormPt30");
    newPartonNewHadronMatchMatrixHadronNormPt50->SetName("newPartonNewHadronMatchMatrixHadronNormPt50");
    newPartonNewHadronMatchMatrixHadronNormPt100->SetName("newPartonNewHadronMatchMatrixHadronNormPt100");

    newPartonNewHadronMatchMatrixPartonNorm = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRC ) ));
    newPartonNewHadronMatchMatrixPartonNormPt20 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt20 ) ));
    newPartonNewHadronMatchMatrixPartonNormPt30 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt30 ) ));
    newPartonNewHadronMatchMatrixPartonNormPt50 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt50 ) ));
    newPartonNewHadronMatchMatrixPartonNormPt100 = fs->make<TH2D>(*( const_cast< TH2D* >( newPartonNewHadronMatchMatrixRCPt100 ) ));
    
    newPartonNewHadronMatchMatrixPartonNorm->SetName("newPartonNewHadronMatchMatrixPartonNorm");
    newPartonNewHadronMatchMatrixPartonNormPt20->SetName("newPartonNewHadronMatchMatrixPartonNormPt20");
    newPartonNewHadronMatchMatrixPartonNormPt30->SetName("newPartonNewHadronMatchMatrixPartonNormPt30");
    newPartonNewHadronMatchMatrixPartonNormPt50->SetName("newPartonNewHadronMatchMatrixPartonNormPt50");
    newPartonNewHadronMatchMatrixPartonNormPt100->SetName("newPartonNewHadronMatchMatrixPartonNormPt100");
    //loop over bin numbers to fill normalized histograms.  Start with normalizing by parton match # for old.
    //NOTE: IF RUNNING MULTIPLE JOBS OVER CRAB AND HADDING THE JOB OUTPUTS, THE CONTENT OF THESE HISTOGRAMS IS NONSENSICAL (PERCENTAGES AREN'T ADDITIVE...)
    for (unsigned int i=1; i <= 4; i++) {
        double numMatchedToParton0 = oldPartonNewHadronMatchMatrixRC->Integral(i,i,1,3);
        double numMatchedToParton20 = oldPartonNewHadronMatchMatrixRCPt20->Integral(i,i,1,3);
        double numMatchedToParton30 = oldPartonNewHadronMatchMatrixRCPt30->Integral(i,i,1,3);
        double numMatchedToParton50 = oldPartonNewHadronMatchMatrixRCPt50->Integral(i,i,1,3);
        double numMatchedToParton100 = oldPartonNewHadronMatchMatrixRCPt100->Integral(i,i,1,3);
        for (unsigned int j = 1; j <= 3; j++) {
            oldPartonNewHadronMatchMatrix->SetBinContent(i,j,oldPartonNewHadronMatchMatrixRC->GetBinContent(i,j)/numMatchedToParton0);
            oldPartonNewHadronMatchMatrixPt20->SetBinContent(i,j,oldPartonNewHadronMatchMatrixRCPt20->GetBinContent(i,j)/numMatchedToParton20);
            oldPartonNewHadronMatchMatrixPt30->SetBinContent(i,j,oldPartonNewHadronMatchMatrixRCPt30->GetBinContent(i,j)/numMatchedToParton30);
            oldPartonNewHadronMatchMatrixPt50->SetBinContent(i,j,oldPartonNewHadronMatchMatrixRCPt50->GetBinContent(i,j)/numMatchedToParton50);
            oldPartonNewHadronMatchMatrixPt100->SetBinContent(i,j,oldPartonNewHadronMatchMatrixRCPt100->GetBinContent(i,j)/numMatchedToParton100);
        }
        
    }
    //now by parton match # for new
    for (unsigned int i=1; i <= 4; i++) {
        double numMatchedToParton0 = newPartonNewHadronMatchMatrixRC->Integral(i,i,1,3);
        double numMatchedToParton20 = newPartonNewHadronMatchMatrixRCPt20->Integral(i,i,1,3);
        double numMatchedToParton30 = newPartonNewHadronMatchMatrixRCPt30->Integral(i,i,1,3);
        double numMatchedToParton50 = newPartonNewHadronMatchMatrixRCPt50->Integral(i,i,1,3);
        double numMatchedToParton100 = newPartonNewHadronMatchMatrixRCPt100->Integral(i,i,1,3);
        for (unsigned int j = 1; j <= 3; j++) {
            newPartonNewHadronMatchMatrixPartonNorm->SetBinContent(i,j,newPartonNewHadronMatchMatrixRC->GetBinContent(i,j)/numMatchedToParton0);
            newPartonNewHadronMatchMatrixPartonNormPt20->SetBinContent(i,j,newPartonNewHadronMatchMatrixRCPt20->GetBinContent(i,j)/numMatchedToParton20);
            newPartonNewHadronMatchMatrixPartonNormPt30->SetBinContent(i,j,newPartonNewHadronMatchMatrixRCPt30->GetBinContent(i,j)/numMatchedToParton30);
            newPartonNewHadronMatchMatrixPartonNormPt50->SetBinContent(i,j,newPartonNewHadronMatchMatrixRCPt50->GetBinContent(i,j)/numMatchedToParton50);
            newPartonNewHadronMatchMatrixPartonNormPt100->SetBinContent(i,j,newPartonNewHadronMatchMatrixRCPt100->GetBinContent(i,j)/numMatchedToParton100);
        }
        
    }
    //now normalize by hadron match #!
    for (unsigned int i=1; i <= 3; i++) {
        double numMatchedToHadron0 = newPartonNewHadronMatchMatrixRC->Integral(1,4,i,i);
        double numMatchedToHadron20 = newPartonNewHadronMatchMatrixRCPt20->Integral(1,4,i,i);
        double numMatchedToHadron30 = newPartonNewHadronMatchMatrixRCPt30->Integral(1,4,i,i);
        double numMatchedToHadron50 = newPartonNewHadronMatchMatrixRCPt50->Integral(1,4,i,i);
        double numMatchedToHadron100 = newPartonNewHadronMatchMatrixRCPt100->Integral(1,4,i,i);
        for (unsigned int j = 1; j <= 4; j++) {
            newPartonNewHadronMatchMatrixHadronNorm->SetBinContent(j,i,newPartonNewHadronMatchMatrixRC->GetBinContent(j,i)/numMatchedToHadron0);
            newPartonNewHadronMatchMatrixHadronNormPt20->SetBinContent(j,i,newPartonNewHadronMatchMatrixRCPt20->GetBinContent(j,i)/numMatchedToHadron20);
            newPartonNewHadronMatchMatrixHadronNormPt30->SetBinContent(j,i,newPartonNewHadronMatchMatrixRCPt30->GetBinContent(j,i)/numMatchedToHadron30);
            newPartonNewHadronMatchMatrixHadronNormPt50->SetBinContent(j,i,newPartonNewHadronMatchMatrixRCPt50->GetBinContent(j,i)/numMatchedToHadron50);
            newPartonNewHadronMatchMatrixHadronNormPt100->SetBinContent(j,i,newPartonNewHadronMatchMatrixRCPt100->GetBinContent(j,i)/numMatchedToHadron100);
        }
        
    }
}

// ------------ method called when starting to processes a run  ------------
void
JetMatchingAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void
JetMatchingAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void
JetMatchingAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void
JetMatchingAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
JetMatchingAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
    //The following says we do not know what parameters are allowed so do no validation
    // Please change this to state exactly what you do use, even if it is no parameters
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(JetMatchingAnalyzer);
