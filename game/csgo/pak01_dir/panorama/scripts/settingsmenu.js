"use strict";
/// <reference path="csgo.d.ts" />
/// <reference path="common/promoted_settings.ts" />
/// <reference path="settingsmenu_shared.ts" />
var SettingsMenu;
(function (SettingsMenu) {
    let activeTab;
    let tabInfo = {
        Promoted: {
            xml: "settings_promoted",
            radioid: "PromotedSettingsRadio"
        },
        KeybdMouseSettings: {
            xml: 'settings_kbmouse',
            radioid: "KBMouseRadio"
        },
        GameSettings: {
            xml: "settings_game",
            radioid: "GameRadio"
        },
        AudioSettings: {
            xml: "settings_audio",
            radioid: "AudioRadio"
        },
        VideoSettings: {
            xml: "settings_video",
            radioid: "VideoRadio"
        },
        Search: {
            xml: "settings_search",
            radioid: "SearchRadio"
        }
    };
    function NavigateToTab(tabID) {
        let bDisplaySteamInputSettings = false;
        let parentPanel = $('#SettingsMenuContent');
        if (!parentPanel.FindChildInLayoutFile(tabID)) {
            let newPanel = $.CreatePanel('Panel', parentPanel, tabID);
            let XmlName = tabInfo[tabID].xml;
            if (bDisplaySteamInputSettings) {
                XmlName = "settings_steaminput";
            }
            newPanel.BLoadLayout('file://{resources}/layout/settings/' + XmlName + '.xml', false, false);
            newPanel.OnPropertyTransitionEndEvent = (panelName, propertyName) => {
                if (newPanel.id === panelName && propertyName === 'opacity') {
                    if (newPanel.visible === true && newPanel.BIsTransparent()) {
                        newPanel.visible = false;
                        newPanel.SetReadyForDisplay(false);
                        return true;
                    }
                }
                return false;
            };
            $.RegisterEventHandler('PropertyTransitionEnd', newPanel, newPanel.OnPropertyTransitionEndEvent);
            newPanel.visible = false;
            let contentPanel = newPanel.FindChildInLayoutFile('SettingsMenuTabContent');
            let jumpButtons = newPanel.FindChildInLayoutFile('SettingsMenuJumpButtons');
            if (contentPanel && jumpButtons) {
                contentPanel.SetSendScrollPositionChangedEvents(true);
                $.RegisterEventHandler('ScrollPositionChanged', contentPanel, () => {
                    if (newPanel.Data().bScrollingToId)
                        newPanel.Data().bScrollingToId = false;
                    else
                        jumpButtons.Children().forEach(jumpButton => jumpButton.checked = false);
                });
                jumpButtons.Children()[0].checked = true;
            }
            const newSettings = PromotedSettingsUtil.GetUnacknowledgedPromotedSettings();
            for (let setting of newSettings) {
                const el = newPanel.FindChildTraverse(setting.id);
                if (el) {
                    el.AddClass("setting-is-new");
                }
            }
        }
        if (tabID == "Search") {
            let settings = parentPanel.FindChildInLayoutFile(tabID);
            let searchTextEntry = settings.FindChildInLayoutFile('SettingsSearchTextEntry');
            searchTextEntry.SetFocus();
        }
        if (activeTab !== tabID) {
            if (activeTab) {
                let panelToHide = $.GetContextPanel().FindChildInLayoutFile(activeTab);
                panelToHide.RemoveClass('Active');
            }
            $("#" + tabInfo[tabID].radioid).checked = true;
            activeTab = tabID;
            let activePanel = $.GetContextPanel().FindChildInLayoutFile(tabID);
            activePanel.AddClass('Active');
            {
                activePanel.visible = true;
                activePanel.SetReadyForDisplay(true);
            }
            SettingsMenuShared.NewTabOpened(activeTab);
        }
    }
    SettingsMenu.NavigateToTab = NavigateToTab;
    function _AccountPrivacySettingsChanged() {
        let gameSettingPanel = $.GetContextPanel().FindChildInLayoutFile("GameSettings");
        if (gameSettingPanel != null) {
            let twitchTvSetting = gameSettingPanel.FindChildInLayoutFile("accountprivacydropdown");
            if (twitchTvSetting != null) {
                // @ts-ignore
                twitchTvSetting.OnShow();
            }
        }
    }
    function _OnSettingsMenuShown() {
        SettingsMenuShared.NewTabOpened(activeTab);
    }
    function _OnSettingsMenuHidden() {
        GameInterfaceAPI.ConsoleCommand("host_writeconfig");
        InventoryAPI.StopItemPreviewMusic();
    }
    function _NavigateToSetting(tab, id) {
        $.DispatchEvent("Activated", $("#" + tabInfo[tab].radioid), "mouse");
        SettingsMenuShared.ScrollToId(id);
    }
    function _NavigateToSettingPanel(tab, submenuRadioId, p) {
        $.DispatchEvent("Activated", $("#" + tabInfo[tab].radioid), "mouse");
        if (submenuRadioId != '') {
            let elSubMenuRadio = $.GetContextPanel().GetParent().FindChildTraverse(submenuRadioId);
            if (elSubMenuRadio) {
                $.DispatchEvent("Activated", elSubMenuRadio, "mouse");
            }
        }
        p.ScrollParentToMakePanelFit(3, false);
        p.AddClass('Highlight');
    }
    function _Init() {
        for (let tab in tabInfo) {
            if (tab !== "Promoted" && tab !== "Search")
                NavigateToTab(tab);
        }
    }
    {
        _Init();
        if (PromotedSettingsUtil.GetUnacknowledgedPromotedSettings().length > 0) {
            NavigateToTab('Promoted');
        }
        else {
            const now = new Date();
            if (g_PromotedSettings.filter(setting => setting.start_date <= now && setting.end_date > now).length == 0)
                $('#PromotedSettingsRadio').visible = false;
            NavigateToTab('VideoSettings');
        }
        MyPersonaAPI.RequestAccountPrivacySettings();
        $.RegisterForUnhandledEvent("PanoramaComponent_MyPersona_AccountPrivacySettingsChanged", _AccountPrivacySettingsChanged);
        $.RegisterEventHandler('ReadyForDisplay', $('#JsSettings'), _OnSettingsMenuShown);
        $.RegisterEventHandler('UnreadyForDisplay', $('#JsSettings'), _OnSettingsMenuHidden);
        $.RegisterForUnhandledEvent('SettingsMenu_NavigateToSetting', _NavigateToSetting);
        $.RegisterForUnhandledEvent('SettingsMenu_NavigateToSettingPanel', _NavigateToSettingPanel);
    }
})(SettingsMenu || (SettingsMenu = {}));
