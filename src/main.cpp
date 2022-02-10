#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>

#include "../library/myFFmpegConversion.hpp"
#include "../library/metadataFunction.hpp"
#include "../library/dnaGenerator.hpp"
#include "../library/utils.hpp"

using namespace std;

int main()
{
    srand(time(NULL));
    
    //GESTIONE LAYER 
    const int numbOfPunkToGen = 100;
    const int scale = 600;
    
    /* To add delay, navigate to library on explorer, then the file named "myFFmpegConversion.ccp, " 
    Under void convertMP4ToGif, navigate to systemCall. There is an FFMPEG command final_delay set to 50.
    This indicates the delay before looping the gif is .5 seconds. You can change this to whatever you desire, 100 = 1 second*/ 

    const bool randomized = false;
    //vettore di stringhe che contiene il nome della cartella in cui sono contenuti i singoli layer
    const vector<string> layerDir = {"Background", "Character", "Headwear", "Shirt", "Trousers","Accessories","Skateboard"};
    //singoli layer specificati
    const vector<vector<string>> singleLayer = 
    {
    {"Blue#25.gif", "Green#30.gif", "Red#40.gif", "White#10.gif"}, 
    
    { "Base_Character#100.gif"},
    
    {"Bird#20.gif", "Cowboy#15.gif", "Helmet#25.gif", "Messy_Hair#10.gif", "None#60.gif", "Orange_Cap#17.gif", "Windy_Hair#13.gif",},
    
    {"None#10.gif", "Tank_Top#40.gif", "TeeShirt#50.gif"},

    {"BlackPants#40.gif", "Jeans#40.gif", /*"None#10.gif"*/ "OrangeShorts#20.gif", "PurpleShorts#20.gif", "RedShorts#50.gif"},
    
    {"Laser_eyes#10.gif","None#90.gif", "Pizza#5.gif"},

    {"Blue#25.gif", "Red#25.gif", "Green#20.gif","Orange#30.gif"}
    };
    
    //GESTIONE METADATA
    const vector<vector<string>> singleLayerName = 
    {
  {"Blue", "Green", "Red", "White"}, 
    
    { "Base Character"},
    
    {"Bird", "Cowboy", "Helmet", "Messy Hair", "None", "Orange Cap", "Windy Hair",},
    
    {"None", "Tank Top", "TeeShirt"},

    {"Black Pants", "Jeans", /*"None"*/ "Orange Shorts", "Purple Shorts", "Red Shorts"},
    
    {"Laser eyes", "None", "Pizza"},

    {"Blue", "Red", "Green","Orange"}
    };
    
    const string name = "Don't Touch That";
    const string description = "The Don't Touch that collective is a collection of 100 Pixel Art NFTs created and Themed off a 2017 viral meme video. Each of the Don't touch that Collective NFT's are uniquely combined with different traits minted on the Ethereum blockchain.";
    const string image = "";
    const vector<pair<string,string>> extraMetadata = 
    {
    {"Compiler", "CeloPunks Algorithm"}
    };
    
    //GESTIONE RARITÀ
    const vector<vector<int>> rarityList = 
    {
    {25, 30, 40, 5}, //5
    {100}, //1
    {8, 9, 10, 8, 50, 9, 6}, //7
    {5, 55, 40}, //3
    {30, 30, /*10*/ 10, 10, 20}, //5
    {6, 90, 4}, //3
    {25, 20, 30, 25}, //4

    };
    
    if(randomized)
        genAndSaveDnaRandomly("../tmp/punksDna", singleLayer, numbOfPunkToGen);
    else
        genAndSaveDnaWithRarity("../tmp/punksDna", singleLayer, rarityList, numbOfPunkToGen);
    generateAllPunksMetadata(layerDir, singleLayerName, name, description, image, extraMetadata, numbOfPunkToGen);
    createRarityFile(layerDir, singleLayerName, numbOfPunkToGen);
    generateAllPunks(layerDir, singleLayer, numbOfPunkToGen, scale);
    
 return 0;
}
