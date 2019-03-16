// hello.cc
#include <node.h>
#include "fm19js.h"
#include "fm19Console\GameVersions.h"
#include "fm19Console\Helpers.h"
#include "fm19Console\service\ServiceMyProfile.h"
#include "fm19Console\service\ServiceCurrentClub.h"
#include "fm19Console\service\ServicePlayer.h"

using namespace v8;
using namespace std;

//Current team setting
unsigned int currentMoney;

//Change team setting
int newMoney;

void fm19js::throwError(char* error, Isolate* isolate) {
  isolate->ThrowException(
    Exception::TypeError(String::NewFromUtf8(isolate, error))
  );
  return;
}

void myProfile(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
	HANDLE phandle = GameLoad(windowName);
    ServiceMyProfile serviceMyProfile;

	//--------------Reputation------------------
	short getHomeRep      = serviceMyProfile.reputation.getHomeRep(phandle);
	short getCurrentRep   = serviceMyProfile.reputation.getCurrentRep(phandle);
	short getWorldRep     = serviceMyProfile.reputation.getWorldRep(phandle);


	//--------------Characteristic--------------
	short getHandsOnApproach     = serviceMyProfile.characteristic.getHandsOnApproach(phandle);
	short getTacticalConsistency = serviceMyProfile.characteristic.getTacticalConsistency(phandle);
	short getClubPlayerLoyalty   = serviceMyProfile.characteristic.getClubPlayerLoyalty(phandle);
	short getSquadDiscipline     = serviceMyProfile.characteristic.getSquadDiscipline(phandle);
	short getFinancialControl    = serviceMyProfile.characteristic.getFinancialControl(phandle);
	int   getMediaHandling       = serviceMyProfile.characteristic.getMediaHandling(phandle);

   Local<Object> obj = Object::New(isolate);
   Local<Object> reputation = Object::New(isolate);
   reputation->Set(String::NewFromUtf8(isolate, "getHomeRep"),  Integer::New(isolate, getHomeRep));
   reputation->Set(String::NewFromUtf8(isolate, "getCurrentRep"),  Integer::New(isolate, getCurrentRep));
   reputation->Set(String::NewFromUtf8(isolate, "getWorldRep"),  Integer::New(isolate, getWorldRep));

   obj->Set(String::NewFromUtf8(isolate, "reputation"), reputation);
   Local<Object> characteristic = Object::New(isolate);

   characteristic->Set(String::NewFromUtf8(isolate, "getHandsOnApproach"),  Integer::New(isolate, getHandsOnApproach));
   characteristic->Set(String::NewFromUtf8(isolate, "getTacticalConsistency"),  Integer::New(isolate, getTacticalConsistency));
   characteristic->Set(String::NewFromUtf8(isolate, "getClubPlayerLoyalty"),  Integer::New(isolate, getClubPlayerLoyalty));
   characteristic->Set(String::NewFromUtf8(isolate, "getSquadDiscipline"),  Integer::New(isolate, getSquadDiscipline));
   characteristic->Set(String::NewFromUtf8(isolate, "getFinancialControl"),  Integer::New(isolate, getFinancialControl));
   characteristic->Set(String::NewFromUtf8(isolate, "getMediaHandling"),  Integer::New(isolate, getMediaHandling));
   // below here i am trying to include the object "obj_lvl" into the first object "obj"

   obj->Set(String::NewFromUtf8(isolate, "characteristic"), characteristic);

       args.GetReturnValue().Set(obj);

}

void currentClub(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HANDLE phandle = GameLoad(windowName);
    ServiceCurrentClub serviceCurrentClub;

    //--------------Reputation------------------
    int getRowId                 = serviceCurrentClub.getRowId(phandle);
    int getUniqeId               = serviceCurrentClub.getUniqeId(phandle);
    char* getFullname            = serviceCurrentClub.getFullname(phandle);
    char* getNickname            = serviceCurrentClub.getNickname(phandle);
    short getTeamType            = serviceCurrentClub.getTeamType(phandle);
    short getReputation          = serviceCurrentClub.getReputation(phandle);
    char* getNation              = serviceCurrentClub.getNation(phandle);
    short getOwnershipType       = serviceCurrentClub.getOwnershipType(phandle);
    short getChairmanTitle       = serviceCurrentClub.getChairmanTitle(phandle);
    short getChairmanStatus      = serviceCurrentClub.getChairmanStatus(phandle);
    short getTrainingFacilities  = serviceCurrentClub.getTrainingFacilities(phandle);
    short getYouthFacilities     = serviceCurrentClub.getYouthFacilities(phandle);
    short getYouthImportance     = serviceCurrentClub.getYouthImportance(phandle);
    short getYouthRecruitment    = serviceCurrentClub.getYouthRecruitment(phandle);
    short getJuniorCoaching      = serviceCurrentClub.getJuniorCoaching(phandle);
    short getCorporateFacilities = serviceCurrentClub.getCorporateFacilities(phandle);
    short getMorale              = serviceCurrentClub.getMorale(phandle);
    short getAverageAttendance   = serviceCurrentClub.getAverageAttendance(phandle);
    short getMinimumAttendance   = serviceCurrentClub.getMinimumAttendance(phandle);


      /*
    //--------------Finances--------------
    short getHandsOnApproach     = serviceMyProfile.characteristic.getHandsOnApproach(phandle);
    short getTacticalConsistency = serviceMyProfile.characteristic.getTacticalConsistency(phandle);
    short getClubPlayerLoyalty   = serviceMyProfile.characteristic.getClubPlayerLoyalty(phandle);
    short getSquadDiscipline     = serviceMyProfile.characteristic.getSquadDiscipline(phandle);
    short getFinancialControl    = serviceMyProfile.characteristic.getFinancialControl(phandle);
    int   getMediaHandling       = serviceMyProfile.characteristic.getMediaHandling(phandle);
    */

    Local<Object> obj = Object::New(isolate);

    Local<Object> information = Object::New(isolate);
    information->Set(String::NewFromUtf8(isolate, "getRowId"),  Integer::New(isolate, getRowId));
    information->Set(String::NewFromUtf8(isolate, "getUniqeId"),  Integer::New(isolate, getUniqeId));
    information->Set(String::NewFromUtf8(isolate, "getFullname"),  String::NewFromUtf8(isolate, getFullname));
    information->Set(String::NewFromUtf8(isolate, "getNickname"),  String::NewFromUtf8(isolate, getNickname));
    information->Set(String::NewFromUtf8(isolate, "getTeamType"),  Integer::New(isolate, getTeamType));
    information->Set(String::NewFromUtf8(isolate, "getReputation"),  Integer::New(isolate, getReputation));
    information->Set(String::NewFromUtf8(isolate, "getNation"),  String::NewFromUtf8(isolate, getNation));
    information->Set(String::NewFromUtf8(isolate, "getOwnershipType"),  Integer::New(isolate, getOwnershipType));
    information->Set(String::NewFromUtf8(isolate, "getChairmanTitle"),  Integer::New(isolate, getChairmanTitle));
    information->Set(String::NewFromUtf8(isolate, "getChairmanStatus"),  Integer::New(isolate, getChairmanStatus));
    information->Set(String::NewFromUtf8(isolate, "getTrainingFacilities"),  Integer::New(isolate,
    getTrainingFacilities));
    information->Set(String::NewFromUtf8(isolate, "getYouthFacilities"),  Integer::New(isolate, getYouthFacilities));
    information->Set(String::NewFromUtf8(isolate, "getYouthImportance"),  Integer::New(isolate, getYouthImportance));
    information->Set(String::NewFromUtf8(isolate, "getYouthRecruitment"),  Integer::New(isolate, getYouthRecruitment));
    information->Set(String::NewFromUtf8(isolate, "getJuniorCoaching"),  Integer::New(isolate, getJuniorCoaching));
    information->Set(String::NewFromUtf8(isolate, "getCorporateFacilities"),  Integer::New(isolate,getCorporateFacilities));
    information->Set(String::NewFromUtf8(isolate, "getMorale"),  Integer::New(isolate, getMorale));
    information->Set(String::NewFromUtf8(isolate, "getAverageAttendance"),  Integer::New(isolate, getAverageAttendance));
    information->Set(String::NewFromUtf8(isolate, "getMinimumAttendance"),  Integer::New(isolate, getMinimumAttendance));


    obj->Set(String::NewFromUtf8(isolate, "information"), information);

    /*
    Local<Object> characteristic = Object::New(isolate);

    characteristic->Set(String::NewFromUtf8(isolate, "getHandsOnApproach"),  Integer::New(isolate, getHandsOnApproach));
    characteristic->Set(String::NewFromUtf8(isolate, "getTacticalConsistency"),  Integer::New(isolate, getTacticalConsistency));
    characteristic->Set(String::NewFromUtf8(isolate, "getClubPlayerLoyalty"),  Integer::New(isolate, getClubPlayerLoyalty));
    characteristic->Set(String::NewFromUtf8(isolate, "getSquadDiscipline"),  Integer::New(isolate, getSquadDiscipline));
    characteristic->Set(String::NewFromUtf8(isolate, "getFinancialControl"),  Integer::New(isolate, getFinancialControl));
    characteristic->Set(String::NewFromUtf8(isolate, "getMediaHandling"),  Integer::New(isolate, getMediaHandling));
    // below here i am trying to include the object "obj_lvl" into the first object "obj"


    obj->Set(String::NewFromUtf8(isolate, "characteristic"), characteristic);
    */

    args.GetReturnValue().Set(obj);

}

void mapEthnicity(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();

    //std::map<int,std::string> results = ServicePlayer::mapEthnicity();


    Local<Object> myArray = Object::New(isolate);

    args.GetReturnValue().Set(myArray);
}




void player(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if (args.Length() != 1 ) {
    fm19js::throwError("requires 1 argument if a callback is being used", isolate);
    return;
    }


    if (!args[0]->IsNumber()) {
      fm19js::throwError("first argument must be a number", isolate);
      return;
    }

    HANDLE phandle = GameLoad(windowName);
    ServicePlayer servicePlayer;
    PlayerDetail player = servicePlayer.getPlayerDetail(phandle, args[0]->IntegerValue());


    Local<Object> obj = Object::New(isolate);
    Local<Object> information = Object::New(isolate);
    Local<Object> attributes = Object::New(isolate);
    Local<Object> technical = Object::New(isolate);
    Local<Object> goalkeeping = Object::New(isolate);
    Local<Object> mental = Object::New(isolate);
    Local<Object> physical = Object::New(isolate);
    Local<Object> hidden = Object::New(isolate);
    Local<Object> positions = Object::New(isolate);
    Local<Object> abilities = Object::New(isolate);
    Local<Object> personality = Object::New(isolate);

    //information
    information->Set(String::NewFromUtf8(isolate, "getRowId"), Integer::New(isolate,  player.getRowID));
    information->Set(String::NewFromUtf8(isolate, "getUniqeID"), Integer::New(isolate, player.getUniqeID));
    information->Set(String::NewFromUtf8(isolate, "getFirstname"),String::NewFromUtf8(isolate, player.getFirstname));
    information->Set(String::NewFromUtf8(isolate, "getLastname"),  String::NewFromUtf8(isolate, player.getLastname));
    information->Set(String::NewFromUtf8(isolate, "getBirthYear"),  Integer::New(isolate, player.getBirthYear));
    information->Set(String::NewFromUtf8(isolate, "getEthnicity"),  Integer::New(isolate, player.getEthnicity));
    information->Set(String::NewFromUtf8(isolate, "getHairColour"),  Integer::New(isolate, player.getHairColour));
    information->Set(String::NewFromUtf8(isolate, "getHairLength"),  Integer::New(isolate, player.getHairLength));
    information->Set(String::NewFromUtf8(isolate, "getSkinTone"),  Integer::New(isolate, player.getSkinTone));
    information->Set(String::NewFromUtf8(isolate, "getHeight"),  Integer::New(isolate, player.getHeight));
    information->Set(String::NewFromUtf8(isolate, "getWeight"),  Integer::New(isolate,player.getWeight));
    information->Set(String::NewFromUtf8(isolate, "getMorale"),  Integer::New(isolate, player.getMorale));
    information->Set(String::NewFromUtf8(isolate, "getDeclaredForNation"),  Integer::New(isolate, player.getDeclaredForNation));
    information->Set(String::NewFromUtf8(isolate, "getInternationalApps"),  Integer::New(isolate, player.getInternationalApps));
    information->Set(String::NewFromUtf8(isolate, "getInternationalGoals"),  Integer::New(isolate, player.getInternationalGoals));
    information->Set(String::NewFromUtf8(isolate, "getGeneralOptions"),  Integer::New(isolate,player.getGeneralOptions));
    information->Set(String::NewFromUtf8(isolate, "getBans"),  Integer::New(isolate, player.getBans));
    information->Set(String::NewFromUtf8(isolate, "getInjuries"),  Integer::New(isolate, player.getInjuries));

    //Technical
    technical->Set(String::NewFromUtf8(isolate, "getInjuries"),  Integer::New(isolate, player.attributes.technical.getCorners ));
    technical->Set(String::NewFromUtf8(isolate, "getCrossing"),  Integer::New(isolate, player.attributes.technical.getCrossing ));
    technical->Set(String::NewFromUtf8(isolate, "getDribbling"),  Integer::New(isolate, player.attributes.technical.getDribbling ));
    technical->Set(String::NewFromUtf8(isolate, "getFinishing"),  Integer::New(isolate,player.attributes.technical.getFinishing ));
    technical->Set(String::NewFromUtf8(isolate, "getFirstTouch"),  Integer::New(isolate, player.attributes.technical.getFirstTouch ));
    technical->Set(String::NewFromUtf8(isolate, "getFreeKickTaking"),  Integer::New(isolate,player.attributes.technical.getFreeKickTaking ));
    technical->Set(String::NewFromUtf8(isolate, "getHeading"),  Integer::New(isolate, player.attributes.technical.getHeading ));
    technical->Set(String::NewFromUtf8(isolate, "getLongShots"),  Integer::New(isolate, player.attributes.technical.getLongShots ));
    technical->Set(String::NewFromUtf8(isolate, "getLongThrows"),  Integer::New(isolate, player.attributes.technical.getLongThrows ));
    technical->Set(String::NewFromUtf8(isolate, "getMarking"),  Integer::New(isolate, player.attributes.technical.getMarking ));
    technical->Set(String::NewFromUtf8(isolate, "getPassing"),  Integer::New(isolate, player.attributes.technical.getPassing ));
    technical->Set(String::NewFromUtf8(isolate, "getPenaltyTaking"),  Integer::New(isolate, player.attributes.technical.getPenaltyTaking ));
    technical->Set(String::NewFromUtf8(isolate, "getTackling"),  Integer::New(isolate, player.attributes.technical.getTackling ));
    technical->Set(String::NewFromUtf8(isolate, "getTechnique"),  Integer::New(isolate, player.attributes.technical.getTechnique ));

    //goalkeeping
    goalkeeping->Set(String::NewFromUtf8(isolate, "getAerialReachs"),  Integer::New(isolate, player.attributes.goalkeeping.getAerialReach));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getCommandOfAreas"),  Integer::New(isolate, player.attributes.goalkeeping.getCommandOfArea));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getCommunications"),  Integer::New(isolate, player.attributes.goalkeeping.getCommunication));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getEccentricitys"),  Integer::New(isolate, player.attributes.goalkeeping.getEccentricity));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getHandlings"),  Integer::New(isolate, player.attributes.goalkeeping.getHandling));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getKickings"),  Integer::New(isolate, player.attributes.goalkeeping.getKicking));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getOneOnOness"),  Integer::New(isolate, player.attributes.goalkeeping.getOneOnOnes));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getReflexess"),  Integer::New(isolate, player.attributes.goalkeeping.getReflexes));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getRushingOuts"),  Integer::New(isolate, player.attributes.goalkeeping.getRushingOut));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getTendencyToPunchs"),  Integer::New(isolate, player.attributes.goalkeeping.getTendencyToPunch));
    goalkeeping->Set(String::NewFromUtf8(isolate, "getThrowings"),  Integer::New(isolate, player.attributes.goalkeeping.getThrowing));

    //-mental
    mental->Set(String::NewFromUtf8(isolate, "getAggression"), Integer::New(isolate,  player.attributes.mental.getAggression));
    mental->Set(String::NewFromUtf8(isolate, "getAnticipation"), Integer::New(isolate,  player.attributes.mental.getAnticipation));
    mental->Set(String::NewFromUtf8(isolate, "getBravery"), Integer::New(isolate,  player.attributes.mental.getBravery));
    mental->Set(String::NewFromUtf8(isolate, "getComposure"), Integer::New(isolate,  player.attributes.mental.getComposure));
    mental->Set(String::NewFromUtf8(isolate, "getConcentration"), Integer::New(isolate,  player.attributes.mental.getConcentration));
    mental->Set(String::NewFromUtf8(isolate, "getDecision"), Integer::New(isolate,  player.attributes.mental.getDecision));
    mental->Set(String::NewFromUtf8(isolate, "getDetermination"), Integer::New(isolate,  player.attributes.mental.getDetermination));
    mental->Set(String::NewFromUtf8(isolate, "getFlair"), Integer::New(isolate,  player.attributes.mental.getFlair));
    mental->Set(String::NewFromUtf8(isolate, "getLeadership"), Integer::New(isolate,  player.attributes.mental.getLeadership));
    mental->Set(String::NewFromUtf8(isolate, "getOffTheBall"), Integer::New(isolate,  player.attributes.mental.getOffTheBall));
    mental->Set(String::NewFromUtf8(isolate, "getPositioning"), Integer::New(isolate,  player.attributes.mental.getPositioning));
    mental->Set(String::NewFromUtf8(isolate, "getTeamwork"), Integer::New(isolate,  player.attributes.mental.getTeamwork));
    mental->Set(String::NewFromUtf8(isolate, "getVision"), Integer::New(isolate,  player.attributes.mental.getVision));
    mental->Set(String::NewFromUtf8(isolate, "getWorkRate"), Integer::New(isolate,  player.attributes.mental.getWorkRate));

    //-physical
    physical->Set(String::NewFromUtf8(isolate, "getAcceleration"), Integer::New(isolate,  player.attributes.physical.getAcceleration));
    physical->Set(String::NewFromUtf8(isolate, "getAgility"), Integer::New(isolate,  player.attributes.physical.getAgility));
    physical->Set(String::NewFromUtf8(isolate, "getBalance"), Integer::New(isolate,  player.attributes.physical.getBalance));
    physical->Set(String::NewFromUtf8(isolate, "getJumpingReach"), Integer::New(isolate,  player.attributes.physical.getJumpingReach));
    physical->Set(String::NewFromUtf8(isolate, "getNaturalFitness"), Integer::New(isolate,  player.attributes.physical.getNaturalFitness));
    physical->Set(String::NewFromUtf8(isolate, "getPace"), Integer::New(isolate,  player.attributes.physical.getPace));
    physical->Set(String::NewFromUtf8(isolate, "getStamina"), Integer::New(isolate,  player.attributes.physical.getStamina));
    physical->Set(String::NewFromUtf8(isolate, "getStrength"), Integer::New(isolate,  player.attributes.physical.getStrength));

    //-hidden
    hidden->Set(String::NewFromUtf8(isolate, "getDirtiness"), Integer::New(isolate,  player.attributes.hidden.getDirtiness));
    hidden->Set(String::NewFromUtf8(isolate, "getConsistency"), Integer::New(isolate,  player.attributes.hidden.getConsistency));
    hidden->Set(String::NewFromUtf8(isolate, "getImpMatches"), Integer::New(isolate,  player.attributes.hidden.getImpMatches));
    hidden->Set(String::NewFromUtf8(isolate, "getInjuryProneness"), Integer::New(isolate,  player.attributes.hidden.getInjuryProneness));
    hidden->Set(String::NewFromUtf8(isolate, "getVersatility"), Integer::New(isolate,  player.attributes.hidden.getVersatility));

    //positions
    positions->Set(String::NewFromUtf8(isolate, "getRoleUsedToFillEmptyAttributes"), Integer::New(isolate,  player.positions.getRoleUsedToFillEmptyAttributes));
    positions->Set(String::NewFromUtf8(isolate, "getPreferredCentralPosition"), Integer::New(isolate,  player.positions.getPreferredCentralPosition));
    positions->Set(String::NewFromUtf8(isolate, "getGK"), Integer::New(isolate,  player.positions.getGK));
    positions->Set(String::NewFromUtf8(isolate, "getSW"), Integer::New(isolate,  player.positions.getSW));
    positions->Set(String::NewFromUtf8(isolate, "getDL"), Integer::New(isolate,  player.positions.getDL));
    positions->Set(String::NewFromUtf8(isolate, "getDC"), Integer::New(isolate,  player.positions.getDC));
    positions->Set(String::NewFromUtf8(isolate, "getDR"), Integer::New(isolate,  player.positions.getDR));
    positions->Set(String::NewFromUtf8(isolate, "getWBL"), Integer::New(isolate,  player.positions.getWBL));
    positions->Set(String::NewFromUtf8(isolate, "getWBR"), Integer::New(isolate,  player.positions.getWBR));
    positions->Set(String::NewFromUtf8(isolate, "getDM"), Integer::New(isolate,  player.positions.getDM));
    positions->Set(String::NewFromUtf8(isolate, "getML"), Integer::New(isolate,  player.positions.getML));
    positions->Set(String::NewFromUtf8(isolate, "getMC"), Integer::New(isolate,  player.positions.getMC));
    positions->Set(String::NewFromUtf8(isolate, "getMR"), Integer::New(isolate,  player.positions.getMR));
    positions->Set(String::NewFromUtf8(isolate, "getAML"), Integer::New(isolate,  player.positions.getAML));
    positions->Set(String::NewFromUtf8(isolate, "getAMC"), Integer::New(isolate,  player.positions.getAMC));
    positions->Set(String::NewFromUtf8(isolate, "getAMR"), Integer::New(isolate,  player.positions.getAMR));
    positions->Set(String::NewFromUtf8(isolate, "getST"), Integer::New(isolate,  player.positions.getST));


    //abilities
    abilities->Set(String::NewFromUtf8(isolate, "getCA"), Integer::New(isolate,  player.abilities.getCA));
    abilities->Set(String::NewFromUtf8(isolate, "getPA"), Integer::New(isolate,  player.abilities.getPA));
    abilities->Set(String::NewFromUtf8(isolate, "getLeftFoot"), Integer::New(isolate,  player.abilities.getLeftFoot));
    abilities->Set(String::NewFromUtf8(isolate, "getRightFoot"), Integer::New(isolate,  player.abilities.getRightFoot));
    abilities->Set(String::NewFromUtf8(isolate, "getMatchSharpness"), Integer::New(isolate,  player.abilities.getMatchSharpness));
    abilities->Set(String::NewFromUtf8(isolate, "getMatchExercise"), Integer::New(isolate,  player.abilities.getMatchExercise));

    attributes->Set(String::NewFromUtf8(isolate, "technical"), technical);
    attributes->Set(String::NewFromUtf8(isolate, "goalkeeping"), goalkeeping);
    attributes->Set(String::NewFromUtf8(isolate, "mental"), mental);
    attributes->Set(String::NewFromUtf8(isolate, "physical"), physical);
    attributes->Set(String::NewFromUtf8(isolate, "hidden"), hidden);

    //personality
    personality->Set(String::NewFromUtf8(isolate, "getAdaptability"), Integer::New(isolate,  player.personality.getAdaptability));
    personality->Set(String::NewFromUtf8(isolate, "getAmbition"), Integer::New(isolate,  player.personality.getAmbition));
    personality->Set(String::NewFromUtf8(isolate, "getControversy"), Integer::New(isolate,  player.personality.getControversy));
    personality->Set(String::NewFromUtf8(isolate, "getLoyalty"), Integer::New(isolate,  player.personality.getLoyalty));
    personality->Set(String::NewFromUtf8(isolate, "getPressure"), Integer::New(isolate,  player.personality.getPressure));
    personality->Set(String::NewFromUtf8(isolate, "getProfessionalism"), Integer::New(isolate,  player.personality.getProfessionalism));
    personality->Set(String::NewFromUtf8(isolate, "getSportmanship"), Integer::New(isolate,  player.personality.getSportmanship));
    personality->Set(String::NewFromUtf8(isolate, "getTemperament"), Integer::New(isolate,  player.personality.getTemperament));

    obj->Set(String::NewFromUtf8(isolate, "information"), information);
    obj->Set(String::NewFromUtf8(isolate, "attributes"), attributes);
    obj->Set(String::NewFromUtf8(isolate, "positions"), positions);
    obj->Set(String::NewFromUtf8(isolate, "abilities"), abilities);
    obj->Set(String::NewFromUtf8(isolate, "personality"), personality);

    args.GetReturnValue().Set(obj);

}


void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "myProfile", myProfile);
  NODE_SET_METHOD(exports, "currentClub", currentClub);
  NODE_SET_METHOD(exports, "player", player);
 //NODE_SET_METHOD(exports, "mapEthnicity", mapEthnicity);

}

NODE_MODULE(fm19js, init)


