# PhoneCaller3-Public-API
This repository introduces a public API for developers who would like to integrate with PhoneCaller jailbreak tweak, I have 3 different types of API

 - **PhoneCallerHelper**: Send query for mobile number and get output from different configured engines
 - **PCInCallView**: UI API: An api that will create a ready-made phonecaller's Popup view, which you can easily add and display anywhere
 - **PCSearchItemVC**: Search result details View Controller, it is a stand-alone presentable ViewController which can be used in for two scenarios :
  1 - Display details for a `PCSearchItem` that is received from the **PhoneCallerHelper** API
  2- Directly fire a search query inside this ViewController

# Usage

After installing PhoneCaller3, you will find libphonecaller3.dylib in /usr/lib. Copy this dylib into $THEOS/lib 
and then copy PhoneCallerHeaders folder into $THEOS/include

in your Tweak.xm, you can import with : 

    #import "PhoneCallerHeaders/PhoneCaller.h"

in your Makefile, add this to the Libraries :

    Tweak_LIBRARIES = phonecaller3
    
    
## Loading Dylib

If your tweak hooks into a specific app, you may need to load dylib manually
    %ctor {
        ...
            void *loadPC = dlopen("/usr/lib/libphonecaller3.dylib", RTLD_LAZY);
            if(loadPC){
              // loaded successfully
            }
        ...
    }


# PhoneCallerHelper

First starting with completion blocks defs

    typedef void(^postRequestBlock)(PCCaller *details);
    typedef void(^searchingBlock)(PCEngine *engine);
    typedef void(^searchCompleteBlock)(PCEngine *engine);
    typedef void(^searchItemBlock)(PCSearchItem *searchItem);

Base public API:

    -(void)searchForNumber:(NSString *)number
    completed:(postRequestBlock)completed
    searching:(searchingBlock)searching
    searchItem:(searchItemBlock)searchItem
    searchComplete:(searchCompleteBlock)searchComplete;

    

> `completed` : In this completion, you receive each output coming from ANY connected engine, PCCaller is a base model that contains three things, name, phone, and image link. (usually you would get many callbacks, which you can prevent later by enabling only one-time-callback)

> `searching`: In this completion, you get an output that the tweak has just started searching in a specific engine, for example started in Showcaller

> `searchItem`: In this completion, you get a one-time callback for an object that can be passed later to 'PCSearchItemVC', in order to see more details about the search query, all outputs, failed/succeeded results, etc.

>  `searchComplete`: You get here that an engine has finished its query

### Example

       [[PhoneCallerHelper alloc] searchForNumber:@"911" completed:^(PCCaller * _Nonnull details) {
            PCLog(@"Got number info .. %@", details);
        } searching:^(PCEngine * _Nonnull engine) {
            PCLog(@"Searching Now.. %@", engine.name);
            
        } searchItem:^(PCSearchItem * _Nonnull item) {
            self.searchItem = item;
        } searchComplete:nil]; // in case you do not need it, just nil it


# PCSearchItemVC
Two main methods:

    -(instancetype)initWithSearchItem:(PCSearchItem *)searchItem;
    -(instancetype)initWithSearchNumber:(NSString *)number;

First one, you can simply init the ViewController with a PCSearchItem object that you recently stored from `PhoneCallerHelper` query, and it will display more details

Second one is as simple as passing the search data/phone number requested , and it will do the rest !

### Example

    PCSearchItemVC *view = [[PCSearchItemVC  alloc] initWithSearchNumber:@"911"];
    
    [self.navigationController  pushViewController:view animated:true];


Note: You don't need to format the phone number, because I already do this, based on the user's country.
