/*
  ==============================================================================

    FilterBank.cpp
    Created: 12 Sep 2015 2:56:38pm
    Author:  Tony Ducks

  ==============================================================================
*/

#include "FilterBank.h"

const double SOS8[50][6]={
    {1,	0,	-1,	1,	-1.9987785419781900,	0.9988117258019110},
    {1,	0,	-1,	1,	-1.9993777884581000,	0.9993866278646940},
    {1,	0,	-1,	1,	-1.9971209427486900,	0.9971471912629550},
    {1,	0,	-1,	1,	-1.9981283386990000,	0.9981394973411570},
    {1,	0,	-1,	1,	-1.9970705594060100,	0.9970876688734220},
    {1,	0,	-1,	1,	-1.9974984404356400,	0.9976304706427330},
    {1,	0,	-1,	1,	-1.9987413356052400,	0.9987765148787840},
    {1,	0,	-1,	1,	-1.9942115653344000,	0.9943159154709810},
    {1,	0,	-1,	1,	-1.9962467971960800,	0.9962911792808700},
    {1,	0,	-1,	1,	-1.9941294437408600,	0.9941974596068910},
    {1,	0,	-1,	1,	-1.9947529222933400,	0.9952779099207740},
    {1,	0,	-1,	1,	-1.9974203055659500,	0.9975602723081400},
    {1,	0,	-1,	1,	-1.9882767015152000,	0.9886909495382260},
    {1,	0,	-1,	1,	-1.9924370967165000,	0.9926134601020490},
    {1,	0,	-1,	1,	-1.9881856999664500,	0.9884556963352590},
    {1,	0,	-1,	1,	-1.9885166329064000,	0.9906014793303250},
    {1,	0,	-1,	1,	-1.9945811687237500,	0.9951376932542060},
    {1,	0,	-1,	1,	-1.9759231162258900,	0.9775629162306730},
    {1,	0,	-1,	1,	-1.9846155078497700,	0.9853150300291520},
    {1,	0,	-1,	1,	-1.9760282949767200,	0.9770969934941140},
    {1,	0,	-1,	1,	-1.9730865461937500,	0.9813437473671320},
    {1,	0,	-1,	1,	-1.9881093386083600,	0.9903192484068190},
    {1,	0,	-1,	1,	-1.9492801783056100,	0.9557344169724620},
    {1,	0,	-1,	1,	-1.9681407430535500,	0.9709050138662140},
    {1,	0,	-1,	1,	-1.9506053344215500,	0.9548113738628170},
    {1,	0,	-1,	1,	-1.9306827437031400,	0.9631890368913960},
    {1,	0,	-1,	1,	-1.9720058599023600,	0.9807567354123720},
    {1,	0,	-1,	1,	-1.8885318974812400,	0.9136446112809490},
    {1,	0,	-1,	1,	-1.9318797491090600,	0.9427215699124380},
    {1,	0,	-1,	1,	-1.8954079912552000,	0.9117751031393520},
    {1,	0,	-1,	1,	-1.8023071503797200,	0.9284162599148670},
    {1,	0,	-1,	1,	-1.9273789280674200,	0.9618100133290710},
    {1,	0,	-1,	1,	-1.7398199745301200,	0.8352580392918490},
    {1,	0,	-1,	1,	-1.8465966688718200,	0.8884670574336160},
    {1,	0,	-1,	1,	-1.7687708335765300,	0.8310442555528910},
    {1,	0,	-1,	1,	-1.3955531779493600,	0.8661403638647370},
    {1,	0,	-1,	1,	-1.7906838470206800,	0.9239734168407860},
    {1,	0,	-1,	1,	-1.6297666243394900,	0.7861277319901490},
    {1,	0,	-1,	1,	-1.3541257698437400,	0.6994784223963890},
    {1,	0,	-1,	1,	-1.4603554506117600,	0.6867963501848830},
    {1,	0,	-1,	1,	-1.3521878785423800,	0.8435403365885230},
    {1,	0,	-1,	1,	-0.2106576849949040,	0.7793891539872490},
    {1,	0,	-1,	1,	-1.0559839509843300,	0.5924242965235340},
    {1,	0,	-1,	1,	-0.3775767119355060,	0.5026597333620270},
    {1,	0,	-1,	1,	-0.6989267851773300,	0.4454818614031410},
    {1,	0,	-1,	1,	-0.1416568013285740,	0.5913639980916540},
    {1,	0,	-1,	1,	 1.8530515046862500,	0.8962482763871150},
    {1,	0,	-1,	1,	 1.6583693624895500,	0.7060764017292220},
    {1,	0,	-1,	1,	 0.0167934472295311,	0.1536898897912410},
    {1,	0,	-1,	1,	 0.8330452984098530,	0.0545720981915791}};
const double G8[50]={
    0.0014576308112768000,
    0.0014576308112768000,
    0.0014565701059445200,
    0.0014565701059445200,
    0.0014561655632890900,
    0.0029070870276006100,
    0.0029070870276006100,
    0.0029028744365330300,
    0.0029028744365330300,
    0.0029012701965546700,
    0.0057951779898874600,
    0.0057951779898874600,
    0.0057784886447897700,
    0.0057784886447897700,
    0.0057721518323703600,
    0.0115421438898502000,
    0.0115421438898502000,
    0.0114763419562426000,
    0.0114763419562426000,
    0.0114515032529433000,
    0.0229471898007297000,
    0.0229471898007297000,
    0.0226902147212009000,
    0.0226902147212009000,
    0.0225943130685917000,
    0.0454567717030985000,
    0.0454567717030985000,
    0.0444720396725626000,
    0.0444720396725626000,
    0.0441124484303241000,
    0.0893899760313232000,
    0.0893899760313232000,
    0.0857540308589821000,
    0.0857540308589821000,
    0.0844778722235543000,
    0.1732048620122510000,
    0.1732048620122510000,
    0.1607080806469280000,
    0.1607080806469280000,
    0.1566018249075580000,
    0.3260579390159850000,
    0.3260579390159850000,
    0.2885206556669380000,
    0.2885206556669380000,
    0.2772590692984290000,
    0.5838478415853340000,
    0.5838478415853340000,
    0.4969627438920420000,
    0.4969627438920420000,
    0.4727139509042110000};

//==============================================================================
BicuadFilter::BicuadFilter(): u1(0), u2(0), active(false){
}

BicuadFilter::~BicuadFilter(){
}

//==============================================================================
void BicuadFilter::makeInactive(){
    active = false;
}

//==============================================================================
void BicuadFilter::setCoeficientes (const double* _coeff,const double* G){
    const double aux1=*G/_coeff[3];
    const double aux2=1.0/_coeff[3];
    
    coeff[0]=_coeff[0]*aux1;
    coeff[1]=_coeff[1]*aux1;
    coeff[2]=_coeff[2]*aux1;
    coeff[3]=_coeff[4]*aux2;
    coeff[4]=_coeff[5]*aux2;
    
    active = true;
}

//==============================================================================
void BicuadFilter::reset(){
    u1 = u2 = 0;
}

//==============================================================================
void BicuadFilter::processSamples (float* const samples, const int numSamples){    
    if (active){
        const float b0 = coeff[0];
        const float b1 = coeff[1];
        const float b2 = coeff[2];
        const float a1 = coeff[3];
        const float a2 = coeff[4];
        float u_1 = u1, u_2 = u2;
        
        for (int i = 0; i < numSamples; i++){
            const float in = samples[i];
            const float out = b0*in + u_1;
            samples[i] = out;
            
            u_1 = b1*in - a1*out + u_2;
            u_2 = b2*in - a2*out;
        }
        u1 = u_1;
        u2 = u_2;
    }
}

/*
 ==============================================================================
 BandFilter Class
 ==============================================================================
*/
BandFilter::BandFilter(int bandFilterOrder){
    for(int i=0;i<bandFilterOrder/2;i++){
        bicuadFiltersArray.add(new BicuadFilter());
    }
}

BandFilter::~BandFilter(){
}

void BandFilter::reset(){
    for(int i=0;i<bicuadFiltersArray.size();i++){
        bicuadFiltersArray[i]->reset();
    }
}

void BandFilter::processSamples (float* const samples, const int numSamples){
    for(int i=0;i<bicuadFiltersArray.size();i++){
        bicuadFiltersArray[i]->processSamples(samples, numSamples);
    }
}

/*
 ==============================================================================
 FilterBank Class
 ==============================================================================
*/
FilterBank::FilterBank(int bandas){
    bandFilterOrder = 10;
    for(int i=0;i<bandas;i++){
        bandFiltersArray.add(new BandFilter(bandFilterOrder));
    }
}

FilterBank::~FilterBank(){
}

void FilterBank::processSamples(float* const input,OwnedArray<Buffer>* outputs,int numSamples){
    for(int i=0; i<bandFiltersArray.size(); i++){
        memcpy(outputs->getUnchecked(i)->getData(), input, numSamples*sizeof(float));
        bandFiltersArray[i]->processSamples(outputs->getUnchecked(i)->getData(), numSamples);
    }
}

void FilterBank::setCoeficientes(){
    const double* G=G8;
    
    for(int i=0; i<bandFiltersArray.size(); i++){
        for(int j=0; j<bandFilterOrder/2; j++){
            const double* coeff= SOS8[5*i+j];
            bandFiltersArray[i]->bicuadFiltersArray[j]->setCoeficientes(coeff, G);
            G++;
        }
    }
}
