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
    virtual const char* partonFlavourToChar(int);
    virtual const char* hadronFlavourToChar(int);
    virtual void analyzeJet(const reco::Jet* , const reco::JetFlavourInfo&, const reco::GenParticleRef,const double);
    virtual void analyze(const edm::Event&, const edm::EventSetup&);
    virtual void endJob() ;
    
    virtual void beginRun(edm::Run const&, edm::EventSetup const&);
    virtual void endRun(edm::Run const&, edm::EventSetup const&);
    virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
    virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
    virtual double DeltaR_Rapidity(const reco::Candidate* const cand1, const reco::Candidate* const cand2);
    // ----------member data ---------------------------
    edm::Service<TFileService> fs;
    edm::InputTag particleSrc, jets_, jetFlavourByRefSrc, subjetFlavourByRefSrc, jetFlavourInfos_, subjetFlavourInfos_,groomedJets_;
    edm::Handle< reco::GenParticleCollection > particles;
    edm::Handle< edm::View< reco::Jet > > jets, groomedJets;
    edm::Handle<reco::JetFlavourInfoMatchingCollection> theJetFlavourInfos,subjetFlavourInfos;
    edm::Handle< reco::JetMatchedPartonsCollection > jetFlavourByRefMatches,subjetFlavourByRefMatches;
    bool useSubjets;
    double hadronMatchDr;
    double jetPtCut;
    int heavyID;
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

    TH2D* oneSubjetHadronFlavour; //b/c/light as fn of pT

    TH2D* twoSubjetsHadronFlavourPT300; //matrix, b/c/light X b/c/light
    TH2D* twoSubjetsHadronFlavourPT500;
    TH2D* twoSubjetsHadronFlavourPT1000;
    TH2D* twoSubjetsPartonFlavourPT300;
    TH2D* twoSubjetsPartonFlavourPT500;
    TH2D* twoSubjetsPartonFlavourPT1000;

    TH2D* numBSubjets_JetPt; //possible cases (no b, one b, two b, three b) as fn of pT
    TH2D* numBSubjets_JetPt_Old;
    
    TH2D* ghostHadronJetDr_JetPt;
    TH2D* bGhostPt_JetPt;
    TH2D* cGhostPt_JetPt;
    TH2D* cGhostPt_JetPt_COld;
    TH2D* cGhostPt_JetPt_LightOld;

    TH1D* hDRFatJetGroomedJet;

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
    TH2D* hNumSubjets;
    TH1D* hGroomedJetMass;
    TH1D* h3SubjetMass;
    TH1D* h3SubjetMass_loop;
    TH1D* hNumBHadronsClustered;
    
    //ofstreams to make text files of events in each category
    // ofstream eventJSON0;
    // ofstream eventJSON2;
    //ofstream eventINFO;
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
    useSubjets = iConfig.getParameter<bool>("useSubjets");
    particleSrc = iConfig.getParameter<InputTag>("particleSource");
    jets_ = ( iConfig.exists("jets") ? iConfig.getParameter<InputTag>("jets") : edm::InputTag() );
    jetFlavourInfos_ = iConfig.getParameter<edm::InputTag> ("jetFlavourInfos");
    jetFlavourByRefSrc = iConfig.getParameter<InputTag>("jetFlavourByRef");
    subjetFlavourByRefSrc = ( iConfig.exists("subjetFlavourByRef") ? iConfig.getParameter<edm::InputTag>("subjetFlavourByRef") : edm::InputTag() );
    hadronMatchDr = iConfig.getParameter<double>("hadronMatchDr");
    jetPtCut = iConfig.getParameter<double>("jetPtCut");
    heavyID = ( iConfig.exists("heavyID") ? iConfig.getParameter<int>("heavyID") : 0 );
    subjetFlavourInfos_ = ( iConfig.exists("subjetFlavourInfos") ? iConfig.getParameter<edm::InputTag>("subjetFlavourInfos") : edm::InputTag() );
    groomedJets_ = ( iConfig.exists("groomedJets") ? iConfig.getParameter<edm::InputTag>("groomedJets") : edm::InputTag() );
    
    //initialize filenames for each ofstream
//     eventJSON0.open("eventJSON0.txt");
//     eventJSON2.open("eventJSON2.txt");
}


JetMatchingAnalyzer::~JetMatchingAnalyzer()
{
    
    // do anything here that needs to be done at desctruction time
    // (e.g. close files, deallocate resources etc.)
    //eventJSON.close();
    //eventINFO.close();
    
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
const char*
JetMatchingAnalyzer::partonFlavourToChar(int flav)
{
    if (flav == 1 || flav == 2 || flav == 3 || flav == 21){
        return "light";
    }
    else if(flav == 4){
        return "c";
    }
    else if (flav == 5){
        return "b";
    }
    else if (flav == 0){
        return "no match";
    }
    else{
        throw cms::Exception("PDGID Issue") << "PDGID Not recognized, investigate!";
    }
}
const char*
JetMatchingAnalyzer::hadronFlavourToChar(int flav)
{
    if (flav == 0){
        return "light";
    }
    else if(flav == 4){
        return "c";
    }
    else if (flav == 5){
        return "b";
    }
    else{
        throw cms::Exception("PDGID Issue") << "PDGID Not recognized, investigate!";
    }
}
void
JetMatchingAnalyzer::analyzeJet(const reco::Jet* iJet, const reco::JetFlavourInfo& aInfo, const reco::GenParticleRef partonRef, const double ungroomedJetPt){
    math::XYZTLorentzVector jetp4 = iJet->p4();
    double jetEt = iJet->et();
    double jetPt = iJet->pt();
    double jetRapidity = iJet->rapidity();
    double jetEta = iJet->eta();
    double jetPhi = iJet->phi();
    
    const reco::GenParticleRefVector & bHadrons = aInfo.getbHadrons();
    const reco::GenParticleRefVector & cHadrons = aInfo.getcHadrons();
    const reco::GenParticleRefVector & partons = aInfo.getPartons();
    bool matchedToGhostHadron = (bHadrons.size() != 0) || (cHadrons.size() != 0);
    
    
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
    if (matchedToGhostHadron) {
        //cout << matchedToGhostHadron << " " << jetPt << " " << closestGhostHadronDr << endl;
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
    bool matchedToBQuark;
    bool matchedToCQuark;
    bool matchedToLightFlavor;
    bool notMatchedToParton;
    
    if (partonRef.isNull()) { //if there is no matched parton
        matchedToBQuark = false;
        matchedToCQuark = false;
        matchedToLightFlavor = false;
        notMatchedToParton = true;
    }
    else {
        const reco::Candidate* parton = partonRef.get();
        const int iPartonFlav = parton->pdgId();
        matchedToBQuark = (abs(iPartonFlav) == 5);
        matchedToCQuark = (abs(iPartonFlav) == 4);
        matchedToLightFlavor = ((abs(iPartonFlav) == 1) || (abs(iPartonFlav) == 2) || (abs(iPartonFlav) == 3) || iPartonFlav == 21);
        //if not matched to b, c, or light parton
        notMatchedToParton = (!matchedToBQuark) && (!matchedToCQuark) && (!matchedToLightFlavor);
    }
    
    //ghost matching
    bool matchedToBHadronGhost = false;
    bool matchedToCHadronGhost = false;
    bool matchedToLightHadronGhost = true;
    
    bool matchedToBPartonGhost = false;
    bool matchedToCPartonGhost = false;
    bool matchedToLightPartonGhost = false;
    bool notMatchedToPartonGhost = false;
    
    int partonGhostFlavour = aInfo.getPartonFlavour();
    int hadronGhostFlavour = aInfo.getHadronFlavour();
    
    //fill booleans for parton ghosts
    if (partonGhostFlavour == 4)
        matchedToCPartonGhost = true;
    else if (partonGhostFlavour == 5)
        matchedToBPartonGhost = true;
    else if (partonGhostFlavour == 1 || partonGhostFlavour == 2 || partonGhostFlavour == 3 || partonGhostFlavour == 21)
        matchedToLightPartonGhost = true;
    else
        notMatchedToPartonGhost = true;
    
    //fill booleans for hadron ghosts.  If flavour isn't 4 or 5, it's zero, so keep default booleans
    if (hadronGhostFlavour == 4) {
        matchedToCHadronGhost = true;
        matchedToLightHadronGhost = false;
    }
    else if (hadronGhostFlavour == 5){
        matchedToBHadronGhost = true;
        matchedToLightHadronGhost = false;
    }
    
    //Do stuff needing a loop over genParticles
    bool matchedToBHadron = false; //for now
    bool matchedToCHadron = false; //for now
    bool matchedToLightHadron = true; //for now.  We assume the jet is a light jet unless matched otherwise.  If otherwise matched, this will be set to false.
    double jetBHadronDr = 10000.; //dr between jet and closest b hadron
    double jetCHadronDr = 10000.; //dr between jet and closest c hadron
    double jetBQuarkDr = 10000.;
    double jetCQuarkDr = 10000.;
    reco::GenParticle* closestBHadron = NULL;
    reco::GenParticle* closestCHadron = NULL;
    reco::GenParticle* closestBQuark = NULL;
    reco::GenParticle* closestCQuark = NULL;
    for (reco::GenParticleCollection::const_iterator iGenPart = particles->begin(); iGenPart != particles->end(); ++iGenPart) {

        double jetParticleDr = reco::deltaR(jetp4, iGenPart->p4());
        int absPartID = abs(iGenPart->pdgId());
        // if the gen particle is a b hadron
        if (((absPartID/100)%10 == 5 || (absPartID/1000)%10 == 5)) {
            if (jetParticleDr < hadronMatchDr){
                matchedToBHadron = true;
                matchedToLightHadron = false; //if matched to a b, it obviously isn't matched to light
            }
            if (jetParticleDr < jetBHadronDr) {
                closestBHadron = const_cast< reco::GenParticle* >(&(*iGenPart));
                //cout << "b hadron dr: " << jetParticleDr << endl;
                jetBHadronDr = jetParticleDr;
            }
        }
        // if the gen particle is a c hadron
        else if ( ((absPartID/100)%10 == 4 || (absPartID/1000)%10 == 4) ) {
            if (jetParticleDr < hadronMatchDr){
                matchedToCHadron = true;
                matchedToLightHadron = false;
            }
            if (jetParticleDr < jetCHadronDr) {
                closestCHadron = const_cast< reco::GenParticle* >(&(*iGenPart));
                //                    cout << "c hadron dr: " << jetParticleDr << endl;
                jetCHadronDr = jetParticleDr;
            }
        }
        //b quark stuff
        else if (absPartID == 5){
            if (jetParticleDr < jetBQuarkDr) {
                closestBQuark = const_cast< reco::GenParticle* >(&(*iGenPart));
                jetBQuarkDr = jetParticleDr;
            }
        }
        else if (absPartID == 4){
            if (jetParticleDr < jetCQuarkDr) {
                closestCQuark = const_cast< reco::GenParticle* >(&(*iGenPart));
                jetCQuarkDr = jetParticleDr;
            }
        }
    } //end loop over genParticles
    
    
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
    
    if (matchedToBQuark && matchedToBHadronGhost) {
        partonNum = 0;
        ghostHadronNum = 0;
    }
    else if (matchedToBQuark && matchedToCHadronGhost){
        partonNum = 0;
        ghostHadronNum = 1;
    }
    else if (matchedToBQuark && matchedToLightHadronGhost) {
        partonNum = 0;
        ghostHadronNum = 2;
    }
    else if (matchedToCQuark && matchedToBHadronGhost) {
        partonNum = 1;
        ghostHadronNum = 0;
    }
    else if (matchedToCQuark && matchedToCHadronGhost){
        partonNum = 1;
        ghostHadronNum = 1;
    }
    else if (matchedToCQuark && matchedToLightHadronGhost) {
        partonNum = 1;
        ghostHadronNum = 2;
    }
    else if (matchedToLightFlavor && matchedToBHadronGhost) {
        partonNum = 2;
        ghostHadronNum = 0;
    }
    else if (matchedToLightFlavor && matchedToCHadronGhost){
        partonNum = 2;
        ghostHadronNum = 1;
    }
    else if (matchedToLightFlavor && matchedToLightHadronGhost) {
        partonNum = 2;
        ghostHadronNum = 2;
    }
    else if (notMatchedToParton && matchedToBHadronGhost) {
        partonNum = 3;
        ghostHadronNum = 0;
    }
    else if (notMatchedToParton && matchedToCHadronGhost){
        partonNum = 3;
        ghostHadronNum = 1;
    }
    else if (notMatchedToParton && matchedToLightHadronGhost) {
        partonNum = 3;
        ghostHadronNum = 2;
    }
    
    if (fabs(jetEta) < 2.5) {
        //fill matrix without pt cut for comparison
        oldPartonNewHadronMatchMatrixRC->Fill(partonNum,ghostHadronNum);
        
        //fill matrices based on pt cut
        if (ungroomedJetPt > 1000) {
            oldPartonNewHadronMatchMatrixRCPt100->Fill(partonNum,ghostHadronNum);
        }
        if (ungroomedJetPt > 500) {
            oldPartonNewHadronMatchMatrixRCPt50->Fill(partonNum,ghostHadronNum);
        }
        if (ungroomedJetPt > 300) {
            oldPartonNewHadronMatchMatrixRCPt30->Fill(partonNum,ghostHadronNum);
        }
        if (ungroomedJetPt > 200) {
            oldPartonNewHadronMatchMatrixRCPt20->Fill(partonNum,ghostHadronNum);
        }
    }//end eta if statement
    
    // parton ghost hadron ghost comparison
    int partonGhostNum = -100;
    ghostHadronNum = -100;
    
    if (matchedToBPartonGhost && matchedToBHadronGhost) {
        partonGhostNum = 0;
        ghostHadronNum = 0;
    }
    else if (matchedToBPartonGhost && matchedToCHadronGhost){
        partonGhostNum = 0;
        ghostHadronNum = 1;
    }
    else if (matchedToBPartonGhost && matchedToLightHadronGhost) {
        partonGhostNum = 0;
        ghostHadronNum = 2;
    }
    else if (matchedToBPartonGhost && matchedToBHadronGhost) {
        partonGhostNum = 1;
        ghostHadronNum = 0;
    }
    else if (matchedToCPartonGhost && matchedToCHadronGhost){
        partonGhostNum = 1;
        ghostHadronNum = 1;
    }
    else if (matchedToCPartonGhost && matchedToLightHadronGhost) {
        partonGhostNum = 1;
        ghostHadronNum = 2;
    }
    else if (matchedToLightPartonGhost && matchedToBHadronGhost) {
        partonGhostNum = 2;
        ghostHadronNum = 0;
    }
    else if (matchedToLightPartonGhost && matchedToCHadronGhost){
        partonGhostNum = 2;
        ghostHadronNum = 1;
    }
    else if (matchedToLightPartonGhost && matchedToLightHadronGhost) {
        partonGhostNum = 2;
        ghostHadronNum = 2;
    }
    else if (notMatchedToPartonGhost && matchedToBHadronGhost) {
        partonGhostNum = 3;
        ghostHadronNum = 0;
    }
    else if (notMatchedToPartonGhost && matchedToCHadronGhost){
        partonGhostNum = 3;
        ghostHadronNum = 1;
    }
    else if (notMatchedToPartonGhost && matchedToLightHadronGhost) {
        partonGhostNum = 3;
        ghostHadronNum = 2;
    }
    if (fabs(jetEta) < 2.5) {
        //fill matrix without pt cut for comparison
        newPartonNewHadronMatchMatrixRC->Fill(partonGhostNum,ghostHadronNum);
        
        //fill matrices based on pt cut
        if (jetPt > 1000) {
            newPartonNewHadronMatchMatrixRCPt100->Fill(partonGhostNum,ghostHadronNum);
        }
        if (jetPt > 500) {
            newPartonNewHadronMatchMatrixRCPt50->Fill(partonGhostNum,ghostHadronNum);
        }
        if (jetPt > 300) {
            newPartonNewHadronMatchMatrixRCPt30->Fill(partonGhostNum,ghostHadronNum);
        }
        if (jetPt > 200) {
            newPartonNewHadronMatchMatrixRCPt20->Fill(partonGhostNum,ghostHadronNum);
        }
    }//end eta if statement
    
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
    //bool eventAdded = false;
    
    
    //    cout << eventAddress << endl;
    //    cout << "run: " << run << endl;
    //    cout << "lumisection: " << lumi << endl;
    //    cout << "event: " << event << endl;
    //    myFile << eventAddress;
    
    iEvent.getByLabel(particleSrc,particles);
    iEvent.getByLabel(jets_, jets);
    iEvent.getByLabel(jetFlavourByRefSrc,jetFlavourByRefMatches);
    iEvent.getByLabel(jetFlavourInfos_ , theJetFlavourInfos );

    //first match all groomed jets to fat jets
    std::map< int,int > groomedJetMatches;
    std::vector<bool> fatJetGroomedLocks(theJetFlavourInfos->size(),false);
    std::vector<bool> fatJetHeavyLocks(theJetFlavourInfos->size(),false);
    if (useSubjets){
        iEvent.getByLabel(groomedJets_, groomedJets);
        iEvent.getByLabel(subjetFlavourByRefSrc,subjetFlavourByRefMatches);
        iEvent.getByLabel(subjetFlavourInfos_,subjetFlavourInfos);
        for(size_t gj=0; gj<groomedJets->size(); ++gj){
            double matchedDR = 1e9;
            int matchedIdx = -1;
            for(reco::JetFlavourInfoMatchingCollection::const_iterator j  = theJetFlavourInfos->begin();j != theJetFlavourInfos->end(); ++j){
                if( fatJetGroomedLocks.at(j - theJetFlavourInfos->begin()) ) continue; // skip jets that have already been matched
                double tempDR = reco::deltaR( j->first->rapidity(), j->first->phi(), groomedJets->at(gj).rapidity(), groomedJets->at(gj).phi() );
                //double tempDR = reco::deltaR( j->first->eta(), j->first->phi(), groomedJets->at(gj).eta(), groomedJets->at(gj).phi() );
                if( tempDR < matchedDR ){
                    matchedDR = tempDR;
                    matchedIdx = (j - theJetFlavourInfos->begin());
                }
            }//end loop over fat jet flavor infos
            if(matchedIdx == -1){
                throw cms::Exception("Jet matching failed") << "Matching groomed to original jets failed. Please check that the jet algorithm, jet size, and Pt threshold match for the two jet collections.";
            }
            else{
                groomedJetMatches[matchedIdx] = gj;
                fatJetGroomedLocks.at(matchedIdx) = true;
                hDRFatJetGroomedJet->Fill(matchedDR);
            }
        }//end loop over groomed jets

        // loop over jets and genParticles to match fat jet to top or higgs
        for (reco::GenParticleCollection::const_iterator iGenPart = particles->begin(); iGenPart != particles->end(); ++iGenPart) {
            int absPartID = abs(iGenPart->pdgId());
            if (absPartID != heavyID) continue;
            int particleStatus = iGenPart->status();
            double tempDR = 1e9;
            int matchIndex = -1;
            for (reco::JetFlavourInfoMatchingCollection::const_iterator iMatch = theJetFlavourInfos->begin(); iMatch != theJetFlavourInfos->end(); ++iMatch) {
                int currentIndex = iMatch - theJetFlavourInfos->begin();
                if ( fatJetHeavyLocks.at(currentIndex) ) continue;
                const reco::Jet* iJet  = (*iMatch).first.get();
                //double jetParticleDr = reco::deltaR(iJet->rapidity(),iJet->phi(),iGenPart->rapidity(),iGenPart->phi());
                double jetParticleDr = reco::deltaR(iJet->eta(),iJet->phi(),iGenPart->eta(),iGenPart->phi());
                if ( (jetParticleDr < tempDR) && (jetParticleDr < 0.3) && (particleStatus == 3) ){
                    tempDR = jetParticleDr;
                    matchIndex = currentIndex;
                }
            } //end loop over fat jet matches
            if (matchIndex == -1){
                //cout << "min dR after jet loop: " << tempDR << endl;
                std::cout << "Couldn't find match for top/higgs!!!" << std::endl;
            }
            else{
                fatJetHeavyLocks.at(matchIndex) = true;
            }
        } //end loop over genParticles

    } //end if(useSubjets)

    for (reco::JetFlavourInfoMatchingCollection::const_iterator iMatch = theJetFlavourInfos->begin(); iMatch != theJetFlavourInfos->end(); ++iMatch) {
        int currentIndex = iMatch - theJetFlavourInfos->begin();
        const reco::Jet* iJet  = (*iMatch).first.get();
        const reco::JetFlavourInfo aInfo = (*iMatch).second;
        const double ungroomedJetPt = iJet->pt();
        //if useSubjets is true, fill the subjet and flavour info vectors with the subjet / subjet flavour infos coming from the higgs or top jets
        if (useSubjets){
            if (heavyID == 0){
                throw cms::Exception("Parameter Issue") << "You want to use subjet mode but did not define a pdgID to match ungroomed fat jets! Example: add heavyID = cms.int32(25) if you are looking at higgs jets.";
            }
            if ( groomedJets->empty() ){
                std::cout << "This event has no groomed jets, skip it!" << std::endl;
                return;
            }
            //if not matched to a higgs/top, go to the next jet...
            if ( ( !fatJetHeavyLocks.at(currentIndex) ) || ( !fatJetGroomedLocks.at(currentIndex) ) ) {
                continue;
            }
            if ( heavyID == 25 ){
                const reco::GenParticleRefVector & bHadrons = aInfo.getbHadrons();
                hNumBHadronsClustered->Fill(bHadrons.size());
                if (bHadrons.size() != 2){
                    continue;
                }
            }
            else if ( heavyID == 6 ){
                const reco::GenParticleRefVector & bHadrons = aInfo.getbHadrons();
                hNumBHadronsClustered->Fill(bHadrons.size());
                if (bHadrons.size() != 1){
                    continue;
                }
            }

            //cut on groomed jet mass.
            int groomedJetIndex = groomedJetMatches[currentIndex];
            double groomedJetMass = groomedJets->at(groomedJetIndex).mass();
            hGroomedJetMass->Fill(groomedJetMass);
            if(groomedJets->at(groomedJetIndex).numberOfDaughters() == 3){
                h3SubjetMass->Fill(groomedJetMass);
            }
            //ignore top jets that don't have three subjets
            if (groomedJets->at(groomedJetIndex).numberOfDaughters() != 3 && heavyID == 6){
                continue;
            }
            double massCutLowEnd = -1.;
            double massCutHighEnd = -1.;
            if(heavyID == 6){
                massCutLowEnd = 145.;
                massCutHighEnd = 205.;
            }
            else if (heavyID == 25){
                massCutLowEnd = 100.;
                massCutHighEnd = 135.;
            }
            else{
                throw cms::Exception("mass cut error!") << "This PDGID does not yet have hard coded mass cuts. Build in your mass cuts in order to run!";
            }
            // TEMPORARILY NOT DOING THE MASS CUT FOR TOPS!!!
            if ( ((groomedJetMass < massCutLowEnd) || (groomedJetMass > massCutHighEnd)) && (heavyID != 6)){
                continue;
            }

            //now that we have the index of the matched groomed jet, use that index to look into the groomed jet collection to get the subjets
            std::vector<int> oldSubjetFlavours;
            std::vector<int> newSubjetFlavours;
            int subjetCounter = 0;
            int maxSubjets = 0;
            if(heavyID == 25){//for higgs --> b + bbar
                maxSubjets = 2;
            }
            else if(heavyID == 6){ //for hadronic top
                maxSubjets = 3;
            }
            else{
                throw cms::Exception("How Many Subjets?") << "Your heavy PDGID was not matched to a subjet count.  Do this!";
            }
            for(size_t s=0; s<groomedJets->at(groomedJetIndex).numberOfDaughters(); ++s){
                //ONLY LOOK AT TWO HARDEST SUBJETS FOR HIGGS
                subjetCounter++;
                if (subjetCounter > maxSubjets) {
                    std::cout << "There are now " << subjetCounter << " subjets!!!!  INVESTIGATE!!!" << std::endl;
                    //break;
                }
                const edm::Ptr<reco::Candidate> & subjet = groomedJets->at(groomedJetIndex).daughterPtr(s);
                for ( reco::JetFlavourInfoMatchingCollection::const_iterator sj  = subjetFlavourInfos->begin(); sj != subjetFlavourInfos->end(); ++sj ) {
                    //see if the subjet the iterator is on corresponds to the one being looped over from the groomed jet's daughters (i.e. its subjets)
                    if( subjet != edm::Ptr<reco::Candidate>((*sj).first.id(), (*sj).first.get(), (*sj).first.key()) ) continue;
                    int subjetIndex = sj - subjetFlavourInfos->begin();
                    const reco::Jet *aSubjet = (*sj).first.get();
                    const reco::JetFlavourInfo tempInfo = (*sj).second;
                    newSubjetFlavours.push_back(tempInfo.getHadronFlavour());
                    //assuming the subjet flavourinfos collection and jetmatchedpartons have the same order (think this is true, but should be tested!)
                    const reco::GenParticleRef partonRef = (*subjetFlavourByRefMatches)[subjetIndex].second.algoDefinitionParton();
                    analyzeJet(aSubjet,tempInfo,partonRef,ungroomedJetPt);
                }
                for (reco::JetMatchedPartonsCollection::const_iterator sjm = subjetFlavourByRefMatches->begin(); sjm != subjetFlavourByRefMatches->end(); ++sjm){
                    if( subjet != edm::Ptr<reco::Candidate>((*sjm).first.id(), (*sjm).first.get(), (*sjm).first.key()) ) continue;
                    int subjetIndex = sjm - subjetFlavourByRefMatches->begin();
                    const reco::Jet *aSubjet = (*sjm).first.get();
                    const reco::GenParticleRef partonRef = (*sjm).second.algoDefinitionParton();
                    int algoFlav;
                    if(partonRef.isNull()){
                        algoFlav = 0;
                    }
                    else{
                        algoFlav = abs(partonRef.get()->pdgId());
                    }
                    oldSubjetFlavours.push_back( algoFlav );
                }

            }
            //analyze subjet flavor combos and fill histograms!
            unsigned int numberOfSubjets = newSubjetFlavours.size();
            if (numberOfSubjets != oldSubjetFlavours.size()){
                throw cms::Exception("flavor vector issue") << "# of new: " << numberOfSubjets << ", # of old: " << oldSubjetFlavours.size() << ". Why don't they match?!";
            }
            if ( numberOfSubjets != groomedJets->at(groomedJetIndex).numberOfDaughters() ){
                std::cout << "numberOfDaughters = " << groomedJets->at(groomedJetIndex).numberOfDaughters() << " and flavor vector size = " << numberOfSubjets << " don't agree, why??" << std::endl;
            }
            //fill histogram to see how many subjets there are for each matched groomed jet (hopefully VERY highly peaked at 2 for h->bb)
            hNumSubjets->Fill(groomedJets->at(groomedJetIndex).numberOfDaughters(),ungroomedJetPt,1);
            int numberOfB = 0;
            int numberOfBOld = 0;
            for (unsigned int i = 0; i<numberOfSubjets; i++){
                if (newSubjetFlavours[i] == 5){
                    numberOfB++;
                }
                if (oldSubjetFlavours[i] == 5){
                    numberOfBOld++;
                }
            }
            numBSubjets_JetPt->Fill(numberOfB, ungroomedJetPt,1);
            //investigate cases for top if numberOfB==0 or 2
            // if(heavyID == 6){
            //     if(numberOfB == 0){
            //         eventJSON0 << eventAddress << "\n";
            //     }
            //     else if(numberOfB == 2){
            //         eventJSON2 << eventAddress << "\n";
            //     }
            // }
            numBSubjets_JetPt_Old->Fill(numberOfBOld, ungroomedJetPt,1);
            if (numberOfSubjets == 0){
                throw cms::Exception("NO SUBJETS!") << "There were no subjets found...What's going on?";
            }
            else if (numberOfSubjets == 1){
                int subjetFlav = newSubjetFlavours[0];
                oneSubjetHadronFlavour->Fill( hadronFlavourToChar(subjetFlav), ungroomedJetPt,1 );
            }
            else if (numberOfSubjets == 2){
                int oldSubjetFlav1 = oldSubjetFlavours[0];
                int oldSubjetFlav2 = oldSubjetFlavours[1];


                int subjetFlav1 = newSubjetFlavours[0];
                int subjetFlav2 = newSubjetFlavours[1];
                if (ungroomedJetPt > 300){
                    twoSubjetsHadronFlavourPT300->Fill( hadronFlavourToChar(subjetFlav1), hadronFlavourToChar(subjetFlav2), 1 );
                    twoSubjetsPartonFlavourPT300->Fill( partonFlavourToChar(oldSubjetFlav1), partonFlavourToChar(oldSubjetFlav2), 1 );
                }
                if (ungroomedJetPt > 500){
                    twoSubjetsHadronFlavourPT500->Fill( hadronFlavourToChar(subjetFlav1), hadronFlavourToChar(subjetFlav2), 1 );
                    twoSubjetsPartonFlavourPT500->Fill( partonFlavourToChar(oldSubjetFlav1), partonFlavourToChar(oldSubjetFlav2), 1 );
                }
                if (ungroomedJetPt > 1000){
                    twoSubjetsHadronFlavourPT1000->Fill( hadronFlavourToChar(subjetFlav1), hadronFlavourToChar(subjetFlav2), 1 );
                    twoSubjetsPartonFlavourPT1000->Fill( partonFlavourToChar(oldSubjetFlav1), partonFlavourToChar(oldSubjetFlav2), 1 );
                }
            }
            else if (numberOfSubjets == 3){
                h3SubjetMass_loop->Fill(groomedJetMass);
            }
            //plots for 
        }//end condition on useSubjets == true
        //normal operation (i.e. if useSubjets == false)
        else{
            const reco::GenParticleRef partonRef = (*jetFlavourByRefMatches)[currentIndex].second.algoDefinitionParton();
            analyzeJet(iJet,aInfo,partonRef,ungroomedJetPt);
        }
        
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
    hJetPtALL = fs->make<TH1D>("hJetPtALL", "Jet Pt",2000,0,2000);
    hJetConstituentNum = fs->make<TH1D>("hJetConstituentNum", "Unmatched Jet Constituent Multiplicity",101,-0.5,100.5);
    hJetConstituentType = fs->make<TH1D>("hJetConstituentType", "Unmatched Jet Constituent PDGID",5601,-0.5,5600.5);
    hJetEta = fs->make<TH1D>("hJetEta", "Unmatched Jet Eta",100,-7,7);
    hJetPhi = fs->make<TH1D>("hJetPhi", "Unmatched Jet Phi",100,0,3.14159);
    hJetPt = fs->make<TH1D>("hJetPt", "Unmatched Jet Pt",600,0,600);
    hJetNum = fs->make<TH1D>("hJetNum", "Jet Multiplicity",61,-0.5,60.5);
    hGroomedJetMass = fs->make<TH1D>("hGroomedJetMass", "Groomed Jet Mass",600,0,600);
    h3SubjetMass = fs->make<TH1D>("h3SubjetMass", "Groomed Jet Mass For Jets With 3 Subjets",600,0,600);
    h3SubjetMass_loop = fs->make<TH1D>("h3SubjetMass_loop", "Groomed Jet Mass For Jets With 3 Subjets",600,0,600);
    ghostHadronJetDr_JetPt = fs->make<TH2D>("ghostHadronJetDr_JetPt","dR Between Jet and Closest Hadron Match VS Jet pT",500,0,500,150,0,1.5);
    bGhostPt_JetPt = fs->make<TH2D>("bGhostPt_JetPt","B Ghost Hadron pT VS Jet pT",500,0,500,500,0,500);
    cGhostPt_JetPt = fs->make<TH2D>("cGhostPt_JetPt","C Ghost Hadron pT VS Jet pT",500,0,500,500,0,500);
    cGhostPt_JetPt_COld = fs->make<TH2D>("cGhostPt_JetPt_COld","C Ghost Hadron pT VS Jet pT (matched to c with old tool)",500,0,500,500,0,500);
    cGhostPt_JetPt_LightOld = fs->make<TH2D>("cGhostPt_JetPt_LightOld","C Ghost Hadron pT VS Jet pT (matched to light flavor with old tool)",500,0,500,500,0,500);
    hNumSubjets = fs->make<TH2D>("hNumSubjets", "Number of Subjets",5,-0.5,4.5,2000,0,2000);
    oneSubjetHadronFlavour = fs->make<TH2D>("oneSubjetHadronFlavour", "Ghost Hadron Flavour Of Subjet",3,-0.5,2.5,2000,0,2000);
    twoSubjetsHadronFlavourPT300 = fs->make<TH2D>("twoSubjetsHadronFlavourPT300", "Ghost Hadron Flavour Of Subjets",3,-0.5,2.5,3,-0.5,2.5);
    twoSubjetsHadronFlavourPT500 = fs->make<TH2D>("twoSubjetsHadronFlavourPT500", "Ghost Hadron Flavour Of Subjets",3,-0.5,2.5,3,-0.5,2.5);
    twoSubjetsHadronFlavourPT1000 = fs->make<TH2D>("twoSubjetsHadronFlavourPT1000", "Ghost Hadron Flavour Of Subjets",3,-0.5,2.5,3,-0.5,2.5);
    twoSubjetsPartonFlavourPT300 = fs->make<TH2D>("twoSubjetsPartonFlavourPT300", "Parton Flavour Of Subjets",4,-0.5,3.5,4,-0.5,3.5);
    twoSubjetsPartonFlavourPT500 = fs->make<TH2D>("twoSubjetsPartonFlavourPT500", "Parton Flavour Of Subjets",4,-0.5,3.5,4,-0.5,3.5);
    twoSubjetsPartonFlavourPT1000 = fs->make<TH2D>("twoSubjetsPartonFlavourT1000", "Parton Flavour Of Subjets",4,-0.5,3.5,4,-0.5,3.5);
    numBSubjets_JetPt = fs->make<TH2D>("numBSubjets_JetPt", "Number of Ghost B Hadron Flavored Subjets",4,-0.5,3.5,2000,0,2000);
    numBSubjets_JetPt_Old = fs->make<TH2D>("numBSubjets_JetPt_Old", "Number of B Parton Flavored Subjets",4,-0.5,3.5,2000,0,2000);
    hDRFatJetGroomedJet = fs->make<TH1D>("hDRFatJetGroomedJet", "dR (rapidity) between groomed jet and closest fat jet",400,0,10);
    hNumBHadronsClustered = fs->make<TH1D>("hNumBHadronsClustered", "Number of Ghost B Hadrons Clustered With Fat Jet",5,-0.5,4.5);
}

// ------------ method called once each job just after ending the event loop  ------------
void
JetMatchingAnalyzer::endJob()
{
    // eventJSON0.close();
    // eventJSON2.close();
    oldPartonNewHadronMatchMatrix = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRC ) ));
    oldPartonNewHadronMatchMatrixPt20 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt20 ) ));
    oldPartonNewHadronMatchMatrixPt30 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt30 ) ));
    oldPartonNewHadronMatchMatrixPt50 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt50 ) ));
    oldPartonNewHadronMatchMatrixPt100 = fs->make<TH2D>(*( const_cast< TH2D* >( oldPartonNewHadronMatchMatrixRCPt100 ) ));
    
    oldPartonNewHadronMatchMatrix->SetName("oldPartonNewHadronMatchMatrix");
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
