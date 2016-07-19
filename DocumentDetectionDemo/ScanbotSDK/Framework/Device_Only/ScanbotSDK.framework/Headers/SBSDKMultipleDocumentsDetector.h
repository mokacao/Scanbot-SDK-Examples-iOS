//
//  SBSDKMultipleDocumentsDetector.h
//  ScanbotSDK
//
//  Created by Andrew Petrus on 06.06.16.
//  Copyright © 2016 doo GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBSDKDocumentDetector.h"

/** @class SBSDKDocumentsDetectorResult
 * This class represents the result of multiple documents detection on an image.
 */
@interface SBSDKDocumentsDetectorResult : NSObject

/** The status of the detection. */
@property(nonatomic, readonly) SBSDKDocumentDetectionStatus status;

/** The detected polygons array or nil, if no polygon was detected. */
@property(nonatomic, strong, readonly) NSArray<SBSDKPolygon *> *polygons;

/** The size of the detector input image. For convenience. */
@property(nonatomic, readonly) CGSize detectorImageSize;

- (instancetype)initWithPolygons:(NSArray<SBSDKPolygon *> *)polygons
                          status:(SBSDKDocumentDetectionStatus)status
               detectorImageSize:(CGSize)detectorImageSize;

@end


@interface SBSDKMultipleDocumentsDetector : NSObject

/**
 * Performs detection using UIImage object as image source
 */
- (SBSDKDocumentsDetectorResult *)detectDocumentPolygonsOnImage:(UIImage *)image;

/**
 * Performs detection using CMSampleBufferRef object as image source
 */
- (SBSDKDocumentsDetectorResult *)detectDocumentPolygonsOnSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end
