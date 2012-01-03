//
//  KirinHelper.h
//  KirinKit
//
//  Created by James Hugman on 21/12/2011.
//  Copyright 2011 Future Platforms. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <KirinKit/JSContext.h>
#import <KirinKit/NativeContext.h>
#import <KirinKit/KirinDropbox.h>

@interface KirinHelper : NSObject {
    NSString* jsModuleName;
    NSObject* nativeObject;
    
    
    @private
    JSContext* jsContext;
    NativeContext* nativeContext;
    KirinDropbox* dropbox;
}

@property(retain) NSString* jsModuleName;
@property(retain) NSObject* nativeObject;
@property(retain) KirinDropbox* dropbox;

- (id) initWithModuleName: (NSString*) moduleName 
          andNativeObject: (NSObject*) obj 
             andJsContext: (JSContext*) ctx 
         andNativeContext: (NativeContext*) nativeCtx
               andDropbox: (KirinDropbox*) dropbox;

/**
 * Call this in places where it makes sense to you lifecycle. 
 * e.g. [UIViewController xibDidJustLoad]
 */
- (void) onLoad;

/*
 * Called by the application implementor where it makes sense in the lifecycle.
 * e.g. [UIViewController viewDidUnload]
 */
- (void) onUnload;

/**
 * Several methods to call Javascript.
 */
- (void) jsMethod: (NSString*) methodName;

- (void) jsMethod:(NSString *)methodName withArgsList:(NSString*) argsList;

- (void) jsCallback: (NSString*) callbackId;

- (void) jsCallback: (NSString*) callbackId withArgsList:(NSString*) argsList;

- (void) jsCallback: (NSString*) callbackName fromConfig: (NSDictionary*) config;

- (void) jsCallback: (NSString*) callbackName fromConfig: (NSDictionary*) config withArgsList:(NSString*) argsList;

    

/**
 * The callbacks are managed within the JS context, so we will need to delete the callbacks when we're finished with them.
 */
- (void) cleanupCallback: (NSString*) callbackId, ...
    NS_REQUIRES_NIL_TERMINATION;

- (void) cleanupCallback: (NSDictionary*) config withNames: (NSString*) callbackName, ...
    NS_REQUIRES_NIL_TERMINATION;




@end
