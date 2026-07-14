#ifndef QLPREVIEWPANEL_H
#define QLPREVIEWPANEL_H

#import <AppKit/AppKit.h>

/*
 * Public QuickLookUI declaration for the Quartz-owned QLPreviewPanel class.
 * QuickLookUI re-exports the class symbols; Quartz provides the implementation.
 */
@interface QLPreviewPanel : NSPanel
+ (instancetype)sharedPreviewPanel;
+ (BOOL)sharedPreviewPanelExists;
- (void)reloadData;
- (void)refreshCurrentPreviewItem;
@end

#endif /* QLPREVIEWPANEL_H */
