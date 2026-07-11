#ifndef QLPREVIEWPANEL_H
#define QLPREVIEWPANEL_H

#import <Foundation/Foundation.h>

/*
 * Compatibility shim for applications that weakly or incidentally link
 * QuickLookUI. Darling does not implement real QuickLook preview UI here.
 */
@interface QLPreviewPanel : NSObject
+ (instancetype)sharedPreviewPanel;
+ (BOOL)sharedPreviewPanelExists;
- (void)reloadData;
- (void)refreshCurrentPreviewItem;
@end

#endif /* QLPREVIEWPANEL_H */
