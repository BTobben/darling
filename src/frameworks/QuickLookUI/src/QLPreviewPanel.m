#import <QuickLookUI/QLPreviewPanel.h>

/*
 * Minimal QuickLookUI compatibility shim.
 *
 * This class only unblocks Objective-C class lookup for software that links
 * QuickLookUI but does not require real preview rendering. It deliberately
 * performs no QuickLook UI work.
 */
@implementation QLPreviewPanel

+ (instancetype)sharedPreviewPanel
{
    static QLPreviewPanel *sharedPanel = nil;
    if (!sharedPanel) {
        sharedPanel = [[self alloc] init];
    }
    return sharedPanel;
}

+ (BOOL)sharedPreviewPanelExists
{
    return NO;
}

- (void)reloadData
{
}

- (void)refreshCurrentPreviewItem
{
}

@end
