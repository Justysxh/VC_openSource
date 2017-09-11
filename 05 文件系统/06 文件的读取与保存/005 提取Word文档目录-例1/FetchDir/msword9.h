// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _Application wrapper class

class _Application : public COleDispatchDriver
{
public:
	_Application() {}		// Calls COleDispatchDriver default constructor
	_Application(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Application(const _Application& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetName();
	LPDISPATCH GetDocuments();
	LPDISPATCH GetWindows();
	LPDISPATCH GetActiveDocument();
	LPDISPATCH GetActiveWindow();
	LPDISPATCH GetSelection();
	LPDISPATCH GetWordBasic();
	LPDISPATCH GetRecentFiles();
	LPDISPATCH GetNormalTemplate();
	LPDISPATCH GetSystem();
	LPDISPATCH GetAutoCorrect();
	LPDISPATCH GetFontNames();
	LPDISPATCH GetLandscapeFontNames();
	LPDISPATCH GetPortraitFontNames();
	LPDISPATCH GetLanguages();
	LPDISPATCH GetAssistant();
	LPDISPATCH GetBrowser();
	LPDISPATCH GetFileConverters();
	LPDISPATCH GetMailingLabel();
	LPDISPATCH GetDialogs();
	LPDISPATCH GetCaptionLabels();
	LPDISPATCH GetAutoCaptions();
	LPDISPATCH GetAddIns();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CString GetVersion();
	BOOL GetScreenUpdating();
	void SetScreenUpdating(BOOL bNewValue);
	BOOL GetPrintPreview();
	void SetPrintPreview(BOOL bNewValue);
	LPDISPATCH GetTasks();
	BOOL GetDisplayStatusBar();
	void SetDisplayStatusBar(BOOL bNewValue);
	BOOL GetSpecialMode();
	long GetUsableWidth();
	long GetUsableHeight();
	BOOL GetMathCoprocessorAvailable();
	BOOL GetMouseAvailable();
	VARIANT GetInternational(long Index);
	CString GetBuild();
	BOOL GetCapsLock();
	BOOL GetNumLock();
	CString GetUserName_();
	void SetUserName(LPCTSTR lpszNewValue);
	CString GetUserInitials();
	void SetUserInitials(LPCTSTR lpszNewValue);
	CString GetUserAddress();
	void SetUserAddress(LPCTSTR lpszNewValue);
	LPDISPATCH GetMacroContainer();
	BOOL GetDisplayRecentFiles();
	void SetDisplayRecentFiles(BOOL bNewValue);
	LPDISPATCH GetCommandBars();
	LPDISPATCH GetSynonymInfo(LPCTSTR Word, VARIANT* LanguageID);
	LPDISPATCH GetVbe();
	CString GetDefaultSaveFormat();
	void SetDefaultSaveFormat(LPCTSTR lpszNewValue);
	LPDISPATCH GetListGalleries();
	CString GetActivePrinter();
	void SetActivePrinter(LPCTSTR lpszNewValue);
	LPDISPATCH GetTemplates();
	LPDISPATCH GetCustomizationContext();
	void SetCustomizationContext(LPDISPATCH newValue);
	LPDISPATCH GetKeyBindings();
	LPDISPATCH GetKeysBoundTo(long KeyCategory, LPCTSTR Command, VARIANT* CommandParameter);
	LPDISPATCH GetFindKey(long KeyCode, VARIANT* KeyCode2);
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	CString GetPath();
	BOOL GetDisplayScrollBars();
	void SetDisplayScrollBars(BOOL bNewValue);
	CString GetStartupPath();
	void SetStartupPath(LPCTSTR lpszNewValue);
	long GetBackgroundSavingStatus();
	long GetBackgroundPrintingStatus();
	long GetLeft();
	void SetLeft(long nNewValue);
	long GetTop();
	void SetTop(long nNewValue);
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetHeight();
	void SetHeight(long nNewValue);
	long GetWindowState();
	void SetWindowState(long nNewValue);
	BOOL GetDisplayAutoCompleteTips();
	void SetDisplayAutoCompleteTips(BOOL bNewValue);
	LPDISPATCH GetOptions();
	long GetDisplayAlerts();
	void SetDisplayAlerts(long nNewValue);
	LPDISPATCH GetCustomDictionaries();
	CString GetPathSeparator();
	void SetStatusBar(LPCTSTR lpszNewValue);
	BOOL GetMAPIAvailable();
	BOOL GetDisplayScreenTips();
	void SetDisplayScreenTips(BOOL bNewValue);
	long GetEnableCancelKey();
	void SetEnableCancelKey(long nNewValue);
	BOOL GetUserControl();
	LPDISPATCH GetFileSearch();
	long GetMailSystem();
	CString GetDefaultTableSeparator();
	void SetDefaultTableSeparator(LPCTSTR lpszNewValue);
	BOOL GetShowVisualBasicEditor();
	void SetShowVisualBasicEditor(BOOL bNewValue);
	CString GetBrowseExtraFileTypes();
	void SetBrowseExtraFileTypes(LPCTSTR lpszNewValue);
	BOOL GetIsObjectValid(LPDISPATCH Object);
	LPDISPATCH GetHangulHanjaDictionaries();
	LPDISPATCH GetMailMessage();
	BOOL GetFocusInMailHeader();
	void Quit(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument);
	void ScreenRefresh();
	void LookupNameProperties(LPCTSTR Name);
	void SubstituteFont(LPCTSTR UnavailableFont, LPCTSTR SubstituteFont);
	BOOL Repeat(VARIANT* Times);
	void DDEExecute(long Channel, LPCTSTR Command);
	long DDEInitiate(LPCTSTR App, LPCTSTR Topic);
	void DDEPoke(long Channel, LPCTSTR Item, LPCTSTR Data);
	CString DDERequest(long Channel, LPCTSTR Item);
	void DDETerminate(long Channel);
	void DDETerminateAll();
	long BuildKeyCode(long Arg1, VARIANT* Arg2, VARIANT* Arg3, VARIANT* Arg4);
	CString KeyString(long KeyCode, VARIANT* KeyCode2);
	void OrganizerCopy(LPCTSTR Source, LPCTSTR Destination, LPCTSTR Name, long Object);
	void OrganizerDelete(LPCTSTR Source, LPCTSTR Name, long Object);
	void OrganizerRename(LPCTSTR Source, LPCTSTR Name, LPCTSTR NewName, long Object);
	// method 'AddAddress' not emitted because of invalid return type or parameter type
	CString GetAddress(VARIANT* Name, VARIANT* AddressProperties, VARIANT* UseAutoText, VARIANT* DisplaySelectDialog, VARIANT* SelectDialog, VARIANT* CheckNamesDialog, VARIANT* RecentAddressesChoice, VARIANT* UpdateRecentAddresses);
	BOOL CheckGrammar(LPCTSTR String);
	BOOL CheckSpelling(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, 
		VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void ResetIgnoreAll();
	LPDISPATCH GetSpellingSuggestions(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
		VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void GoBack();
	void Help(VARIANT* HelpType);
	void AutomaticChange();
	void ShowMe();
	void HelpTool();
	LPDISPATCH NewWindow();
	void ListCommands(BOOL ListAllCommands);
	void ShowClipboard();
	void OnTime(VARIANT* When, LPCTSTR Name, VARIANT* Tolerance);
	void NextLetter();
	short MountVolume(LPCTSTR Zone, LPCTSTR Server, LPCTSTR Volume, VARIANT* User, VARIANT* UserPassword, VARIANT* VolumePassword);
	CString CleanString(LPCTSTR String);
	void SendFax();
	void ChangeFileOpenDirectory(LPCTSTR Path);
	void GoForward();
	void Move(long Left, long Top);
	void Resize(long Width, long Height);
	float InchesToPoints(float Inches);
	float CentimetersToPoints(float Centimeters);
	float MillimetersToPoints(float Millimeters);
	float PicasToPoints(float Picas);
	float LinesToPoints(float Lines);
	float PointsToInches(float Points);
	float PointsToCentimeters(float Points);
	float PointsToMillimeters(float Points);
	float PointsToPicas(float Points);
	float PointsToLines(float Points);
	void Activate();
	float PointsToPixels(float Points, VARIANT* fVertical);
	float PixelsToPoints(float Pixels, VARIANT* fVertical);
	void KeyboardLatin();
	void KeyboardBidi();
	void ToggleKeyboard();
	long Keyboard(long LangId);
	CString ProductCode();
	LPDISPATCH DefaultWebOptions();
	void SetDefaultTheme(LPCTSTR Name, long DocumentType);
	CString GetDefaultTheme(long DocumentType);
	LPDISPATCH GetEmailOptions();
	long GetLanguage();
	LPDISPATCH GetCOMAddIns();
	BOOL GetCheckLanguage();
	void SetCheckLanguage(BOOL bNewValue);
	LPDISPATCH GetLanguageSettings();
	LPDISPATCH GetAnswerWizard();
	long GetFeatureInstall();
	void SetFeatureInstall(long nNewValue);
	void PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* FileName, VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight);
	VARIANT Run(LPCTSTR MacroName, VARIANT* varg1, VARIANT* varg2, VARIANT* varg3, VARIANT* varg4, VARIANT* varg5, VARIANT* varg6, VARIANT* varg7, VARIANT* varg8, VARIANT* varg9, VARIANT* varg10, VARIANT* varg11, VARIANT* varg12, VARIANT* varg13, 
		VARIANT* varg14, VARIANT* varg15, VARIANT* varg16, VARIANT* varg17, VARIANT* varg18, VARIANT* varg19, VARIANT* varg20, VARIANT* varg21, VARIANT* varg22, VARIANT* varg23, VARIANT* varg24, VARIANT* varg25, VARIANT* varg26, VARIANT* varg27, 
		VARIANT* varg28, VARIANT* varg29, VARIANT* varg30);
};
/////////////////////////////////////////////////////////////////////////////
// Documents wrapper class

class Documents : public COleDispatchDriver
{
public:
	Documents() {}		// Calls COleDispatchDriver default constructor
	Documents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Documents(const Documents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(VARIANT* Index);
	void Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument);
	void Save(VARIANT* NoPrompt, VARIANT* OriginalFormat);
	LPDISPATCH Add(VARIANT* Template, VARIANT* NewTemplate, VARIANT* DocumentType, VARIANT* Visible);
	LPDISPATCH Open(VARIANT* FileName, VARIANT* ConfirmConversions, VARIANT* ReadOnly, VARIANT* AddToRecentFiles, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* Revert, VARIANT* WritePasswordDocument, 
		VARIANT* WritePasswordTemplate, VARIANT* Format, VARIANT* Encoding, VARIANT* Visible);
};
/////////////////////////////////////////////////////////////////////////////
// _Document wrapper class

class _Document : public COleDispatchDriver
{
public:
	_Document() {}		// Calls COleDispatchDriver default constructor
	_Document(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Document(const _Document& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetName();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetBuiltInDocumentProperties();
	LPDISPATCH GetCustomDocumentProperties();
	CString GetPath();
	LPDISPATCH GetBookmarks();
	LPDISPATCH GetTables();
	LPDISPATCH GetFootnotes();
	LPDISPATCH GetEndnotes();
	LPDISPATCH GetComments();
	long GetType();
	BOOL GetAutoHyphenation();
	void SetAutoHyphenation(BOOL bNewValue);
	BOOL GetHyphenateCaps();
	void SetHyphenateCaps(BOOL bNewValue);
	long GetHyphenationZone();
	void SetHyphenationZone(long nNewValue);
	long GetConsecutiveHyphensLimit();
	void SetConsecutiveHyphensLimit(long nNewValue);
	LPDISPATCH GetSections();
	LPDISPATCH GetParagraphs();
	LPDISPATCH GetWords();
	LPDISPATCH GetSentences();
	LPDISPATCH GetCharacters();
	LPDISPATCH GetFields();
	LPDISPATCH GetFormFields();
	LPDISPATCH GetStyles();
	LPDISPATCH GetFrames();
	LPDISPATCH GetTablesOfFigures();
	LPDISPATCH GetVariables();
	LPDISPATCH GetMailMerge();
	LPDISPATCH GetEnvelope();
	CString GetFullName();
	LPDISPATCH GetRevisions();
	LPDISPATCH GetTablesOfContents();
	LPDISPATCH GetTablesOfAuthorities();
	LPDISPATCH GetPageSetup();
	void SetPageSetup(LPDISPATCH newValue);
	LPDISPATCH GetWindows();
	BOOL GetHasRoutingSlip();
	void SetHasRoutingSlip(BOOL bNewValue);
	LPDISPATCH GetRoutingSlip();
	BOOL GetRouted();
	LPDISPATCH GetTablesOfAuthoritiesCategories();
	LPDISPATCH GetIndexes();
	BOOL GetSaved();
	void SetSaved(BOOL bNewValue);
	LPDISPATCH GetContent();
	LPDISPATCH GetActiveWindow();
	long GetKind();
	void SetKind(long nNewValue);
	BOOL GetReadOnly();
	LPDISPATCH GetSubdocuments();
	BOOL GetIsMasterDocument();
	float GetDefaultTabStop();
	void SetDefaultTabStop(float newValue);
	BOOL GetEmbedTrueTypeFonts();
	void SetEmbedTrueTypeFonts(BOOL bNewValue);
	BOOL GetSaveFormsData();
	void SetSaveFormsData(BOOL bNewValue);
	BOOL GetReadOnlyRecommended();
	void SetReadOnlyRecommended(BOOL bNewValue);
	BOOL GetSaveSubsetFonts();
	void SetSaveSubsetFonts(BOOL bNewValue);
	BOOL GetCompatibility(long Type);
	void SetCompatibility(long Type, BOOL bNewValue);
	LPDISPATCH GetStoryRanges();
	LPDISPATCH GetCommandBars();
	BOOL GetIsSubdocument();
	long GetSaveFormat();
	long GetProtectionType();
	LPDISPATCH GetHyperlinks();
	LPDISPATCH GetShapes();
	LPDISPATCH GetListTemplates();
	LPDISPATCH GetLists();
	BOOL GetUpdateStylesOnOpen();
	void SetUpdateStylesOnOpen(BOOL bNewValue);
	VARIANT GetAttachedTemplate();
	void SetAttachedTemplate(VARIANT* newValue);
	LPDISPATCH GetInlineShapes();
	LPDISPATCH GetBackground();
	void SetBackground(LPDISPATCH newValue);
	BOOL GetGrammarChecked();
	void SetGrammarChecked(BOOL bNewValue);
	BOOL GetSpellingChecked();
	void SetSpellingChecked(BOOL bNewValue);
	BOOL GetShowGrammaticalErrors();
	void SetShowGrammaticalErrors(BOOL bNewValue);
	BOOL GetShowSpellingErrors();
	void SetShowSpellingErrors(BOOL bNewValue);
	LPDISPATCH GetVersions();
	BOOL GetShowSummary();
	void SetShowSummary(BOOL bNewValue);
	long GetSummaryViewMode();
	void SetSummaryViewMode(long nNewValue);
	long GetSummaryLength();
	void SetSummaryLength(long nNewValue);
	BOOL GetPrintFractionalWidths();
	void SetPrintFractionalWidths(BOOL bNewValue);
	BOOL GetPrintPostScriptOverText();
	void SetPrintPostScriptOverText(BOOL bNewValue);
	LPDISPATCH GetContainer();
	BOOL GetPrintFormsData();
	void SetPrintFormsData(BOOL bNewValue);
	LPDISPATCH GetListParagraphs();
	void SetPassword(LPCTSTR lpszNewValue);
	void SetWritePassword(LPCTSTR lpszNewValue);
	BOOL GetHasPassword();
	BOOL GetWriteReserved();
	CString GetActiveWritingStyle(VARIANT* LanguageID);
	void SetActiveWritingStyle(VARIANT* LanguageID, LPCTSTR lpszNewValue);
	BOOL GetUserControl();
	void SetUserControl(BOOL bNewValue);
	BOOL GetHasMailer();
	void SetHasMailer(BOOL bNewValue);
	LPDISPATCH GetMailer();
	LPDISPATCH GetReadabilityStatistics();
	LPDISPATCH GetGrammaticalErrors();
	LPDISPATCH GetSpellingErrors();
	LPDISPATCH GetVBProject();
	BOOL GetFormsDesign();
	CString Get_CodeName();
	void Set_CodeName(LPCTSTR lpszNewValue);
	CString GetCodeName();
	BOOL GetSnapToGrid();
	void SetSnapToGrid(BOOL bNewValue);
	BOOL GetSnapToShapes();
	void SetSnapToShapes(BOOL bNewValue);
	float GetGridDistanceHorizontal();
	void SetGridDistanceHorizontal(float newValue);
	float GetGridDistanceVertical();
	void SetGridDistanceVertical(float newValue);
	float GetGridOriginHorizontal();
	void SetGridOriginHorizontal(float newValue);
	float GetGridOriginVertical();
	void SetGridOriginVertical(float newValue);
	long GetGridSpaceBetweenHorizontalLines();
	void SetGridSpaceBetweenHorizontalLines(long nNewValue);
	long GetGridSpaceBetweenVerticalLines();
	void SetGridSpaceBetweenVerticalLines(long nNewValue);
	BOOL GetGridOriginFromMargin();
	void SetGridOriginFromMargin(BOOL bNewValue);
	BOOL GetKerningByAlgorithm();
	void SetKerningByAlgorithm(BOOL bNewValue);
	long GetJustificationMode();
	void SetJustificationMode(long nNewValue);
	long GetFarEastLineBreakLevel();
	void SetFarEastLineBreakLevel(long nNewValue);
	CString GetNoLineBreakBefore();
	void SetNoLineBreakBefore(LPCTSTR lpszNewValue);
	CString GetNoLineBreakAfter();
	void SetNoLineBreakAfter(LPCTSTR lpszNewValue);
	BOOL GetTrackRevisions();
	void SetTrackRevisions(BOOL bNewValue);
	BOOL GetPrintRevisions();
	void SetPrintRevisions(BOOL bNewValue);
	BOOL GetShowRevisions();
	void SetShowRevisions(BOOL bNewValue);
	void Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument);
	void SaveAs(VARIANT* FileName, VARIANT* FileFormat, VARIANT* LockComments, VARIANT* Password, VARIANT* AddToRecentFiles, VARIANT* WritePassword, VARIANT* ReadOnlyRecommended, VARIANT* EmbedTrueTypeFonts, VARIANT* SaveNativePictureFormat, 
		VARIANT* SaveFormsData, VARIANT* SaveAsAOCELetter);
	void Repaginate();
	void FitToPages();
	void ManualHyphenation();
	void Select();
	void DataForm();
	void Route();
	void Save();
	void SendMail();
	LPDISPATCH Range(VARIANT* Start, VARIANT* End);
	void RunAutoMacro(long Which);
	void Activate();
	void PrintPreview();
	LPDISPATCH GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name);
	BOOL Undo(VARIANT* Times);
	BOOL Redo(VARIANT* Times);
	long ComputeStatistics(long Statistic, VARIANT* IncludeFootnotesAndEndnotes);
	void MakeCompatibilityDefault();
	void Protect(long Type, VARIANT* NoReset, VARIANT* Password);
	void Unprotect(VARIANT* Password);
	void EditionOptions(long Type, long Option, LPCTSTR Name, VARIANT* Format);
	void RunLetterWizard(VARIANT* LetterContent, VARIANT* WizardMode);
	LPDISPATCH GetLetterContent();
	void SetLetterContent(VARIANT* LetterContent);
	void CopyStylesFromTemplate(LPCTSTR Template);
	void UpdateStyles();
	void CheckGrammar();
	void CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
		VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void FollowHyperlink(VARIANT* Address, VARIANT* SubAddress, VARIANT* NewWindow, VARIANT* AddHistory, VARIANT* ExtraInfo, VARIANT* Method, VARIANT* HeaderInfo);
	void AddToFavorites();
	void Reload();
	LPDISPATCH AutoSummarize(VARIANT* Length, VARIANT* Mode, VARIANT* UpdateProperties);
	void RemoveNumbers(VARIANT* NumberType);
	void ConvertNumbersToText(VARIANT* NumberType);
	long CountNumberedItems(VARIANT* NumberType, VARIANT* Level);
	void Post();
	void ToggleFormsDesign();
	void Compare(LPCTSTR Name);
	void UpdateSummaryProperties();
	VARIANT GetCrossReferenceItems(VARIANT* ReferenceType);
	void AutoFormat();
	void ViewCode();
	void ViewPropertyBrowser();
	void ForwardMailer();
	void Reply();
	void ReplyAll();
	void SendMailer(VARIANT* FileFormat, VARIANT* Priority);
	void UndoClear();
	void PresentIt();
	void SendFax(LPCTSTR Address, VARIANT* Subject);
	void Merge(LPCTSTR FileName);
	void ClosePrintPreview();
	void CheckConsistency();
	LPDISPATCH CreateLetterContent(LPCTSTR DateFormat, BOOL IncludeHeaderFooter, LPCTSTR PageDesign, long LetterStyle, BOOL Letterhead, long LetterheadLocation, float LetterheadSize, LPCTSTR RecipientName, LPCTSTR RecipientAddress, 
		LPCTSTR Salutation, long SalutationType, LPCTSTR RecipientReference, LPCTSTR MailingInstructions, LPCTSTR AttentionLine, LPCTSTR Subject, LPCTSTR CCList, LPCTSTR ReturnAddress, LPCTSTR SenderName, LPCTSTR Closing, LPCTSTR SenderCompany, 
		LPCTSTR SenderJobTitle, LPCTSTR SenderInitials, long EnclosureNumber, VARIANT* InfoBlock, VARIANT* RecipientCode, VARIANT* RecipientGender, VARIANT* ReturnAddressShortForm, VARIANT* SenderCity, VARIANT* SenderCode, VARIANT* SenderGender, 
		VARIANT* SenderReference);
	void AcceptAllRevisions();
	void RejectAllRevisions();
	void DetectLanguage();
	void ApplyTheme(LPCTSTR Name);
	void RemoveTheme();
	void WebPagePreview();
	void ReloadAs(long Encoding);
	CString GetActiveTheme();
	CString GetActiveThemeDisplayName();
	LPDISPATCH GetEmail();
	LPDISPATCH GetScripts();
	BOOL GetLanguageDetected();
	void SetLanguageDetected(BOOL bNewValue);
	long GetFarEastLineBreakLanguage();
	void SetFarEastLineBreakLanguage(long nNewValue);
	LPDISPATCH GetFrameset();
	VARIANT GetClickAndTypeParagraphStyle();
	void SetClickAndTypeParagraphStyle(VARIANT* newValue);
	LPDISPATCH GetHTMLProject();
	LPDISPATCH GetWebOptions();
	long GetOpenEncoding();
	long GetSaveEncoding();
	void SetSaveEncoding(long nNewValue);
	BOOL GetOptimizeForWord97();
	void SetOptimizeForWord97(BOOL bNewValue);
	BOOL GetVBASigned();
	void PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight);
};
/////////////////////////////////////////////////////////////////////////////
// Template wrapper class

class Template : public COleDispatchDriver
{
public:
	Template() {}		// Calls COleDispatchDriver default constructor
	Template(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Template(const Template& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetName();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetPath();
	LPDISPATCH GetAutoTextEntries();
	long GetLanguageID();
	void SetLanguageID(long nNewValue);
	BOOL GetSaved();
	void SetSaved(BOOL bNewValue);
	long GetType();
	CString GetFullName();
	LPDISPATCH GetBuiltInDocumentProperties();
	LPDISPATCH GetCustomDocumentProperties();
	LPDISPATCH GetListTemplates();
	long GetLanguageIDFarEast();
	void SetLanguageIDFarEast(long nNewValue);
	LPDISPATCH GetVBProject();
	BOOL GetKerningByAlgorithm();
	void SetKerningByAlgorithm(BOOL bNewValue);
	long GetJustificationMode();
	void SetJustificationMode(long nNewValue);
	long GetFarEastLineBreakLevel();
	void SetFarEastLineBreakLevel(long nNewValue);
	CString GetNoLineBreakBefore();
	void SetNoLineBreakBefore(LPCTSTR lpszNewValue);
	CString GetNoLineBreakAfter();
	void SetNoLineBreakAfter(LPCTSTR lpszNewValue);
	LPDISPATCH OpenAsDocument();
	void Save();
	long GetNoProofing();
	void SetNoProofing(long nNewValue);
	long GetFarEastLineBreakLanguage();
	void SetFarEastLineBreakLanguage(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// Templates wrapper class

class Templates : public COleDispatchDriver
{
public:
	Templates() {}		// Calls COleDispatchDriver default constructor
	Templates(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Templates(const Templates& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long GetCount();
	LPUNKNOWN Get_NewEnum();
	LPDISPATCH Item(VARIANT* Index);
};
/////////////////////////////////////////////////////////////////////////////
// Bookmark wrapper class

class Bookmark : public COleDispatchDriver
{
public:
	Bookmark() {}		// Calls COleDispatchDriver default constructor
	Bookmark(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Bookmark(const Bookmark& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetName();
	LPDISPATCH GetRange();
	BOOL GetEmpty();
	long GetStart();
	void SetStart(long nNewValue);
	long GetEnd();
	void SetEnd(long nNewValue);
	BOOL GetColumn();
	long GetStoryType();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	void Select();
	void Delete();
	LPDISPATCH Copy(LPCTSTR Name);
};
/////////////////////////////////////////////////////////////////////////////
// Bookmarks wrapper class

class Bookmarks : public COleDispatchDriver
{
public:
	Bookmarks() {}		// Calls COleDispatchDriver default constructor
	Bookmarks(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Bookmarks(const Bookmarks& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	long GetDefaultSorting();
	void SetDefaultSorting(long nNewValue);
	BOOL GetShowHidden();
	void SetShowHidden(BOOL bNewValue);
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(VARIANT* Index);
	LPDISPATCH Add(LPCTSTR Name, VARIANT* Range);
	BOOL Exists(LPCTSTR Name);
};
/////////////////////////////////////////////////////////////////////////////
// Variable wrapper class

class Variable : public COleDispatchDriver
{
public:
	Variable() {}		// Calls COleDispatchDriver default constructor
	Variable(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Variable(const Variable& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetName();
	CString GetValue();
	void SetValue(LPCTSTR lpszNewValue);
	long GetIndex();
	void Delete();
};
/////////////////////////////////////////////////////////////////////////////
// Variables wrapper class

class Variables : public COleDispatchDriver
{
public:
	Variables() {}		// Calls COleDispatchDriver default constructor
	Variables(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Variables(const Variables& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(VARIANT* Index);
	LPDISPATCH Add(LPCTSTR Name, VARIANT* Value);
};
/////////////////////////////////////////////////////////////////////////////
// Window wrapper class

class Window : public COleDispatchDriver
{
public:
	Window() {}		// Calls COleDispatchDriver default constructor
	Window(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Window(const Window& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetActivePane();
	LPDISPATCH GetDocument();
	LPDISPATCH GetPanes();
	LPDISPATCH GetSelection();
	long GetLeft();
	void SetLeft(long nNewValue);
	long GetTop();
	void SetTop(long nNewValue);
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetHeight();
	void SetHeight(long nNewValue);
	BOOL GetSplit();
	void SetSplit(BOOL bNewValue);
	long GetSplitVertical();
	void SetSplitVertical(long nNewValue);
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	long GetWindowState();
	void SetWindowState(long nNewValue);
	BOOL GetDisplayRulers();
	void SetDisplayRulers(BOOL bNewValue);
	BOOL GetDisplayVerticalRuler();
	void SetDisplayVerticalRuler(BOOL bNewValue);
	LPDISPATCH GetView();
	long GetType();
	LPDISPATCH GetNext();
	LPDISPATCH GetPrevious();
	long GetWindowNumber();
	BOOL GetDisplayVerticalScrollBar();
	void SetDisplayVerticalScrollBar(BOOL bNewValue);
	BOOL GetDisplayHorizontalScrollBar();
	void SetDisplayHorizontalScrollBar(BOOL bNewValue);
	float GetStyleAreaWidth();
	void SetStyleAreaWidth(float newValue);
	BOOL GetDisplayScreenTips();
	void SetDisplayScreenTips(BOOL bNewValue);
	long GetHorizontalPercentScrolled();
	void SetHorizontalPercentScrolled(long nNewValue);
	long GetVerticalPercentScrolled();
	void SetVerticalPercentScrolled(long nNewValue);
	BOOL GetDocumentMap();
	void SetDocumentMap(BOOL bNewValue);
	BOOL GetActive();
	long GetDocumentMapPercentWidth();
	void SetDocumentMapPercentWidth(long nNewValue);
	long GetIndex();
	long GetIMEMode();
	void SetIMEMode(long nNewValue);
	void Activate();
	void Close(VARIANT* SaveChanges, VARIANT* RouteDocument);
	void LargeScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft);
	void SmallScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft);
	LPDISPATCH NewWindow();
	void PageScroll(VARIANT* Down, VARIANT* Up);
	void SetFocus();
	LPDISPATCH RangeFromPoint(long x, long y);
	void ScrollIntoView(LPDISPATCH obj, VARIANT* Start);
	void GetPoint(long* ScreenPixelsLeft, long* ScreenPixelsTop, long* ScreenPixelsWidth, long* ScreenPixelsHeight, LPDISPATCH obj);
	void PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight);
	long GetUsableWidth();
	long GetUsableHeight();
	BOOL GetEnvelopeVisible();
	void SetEnvelopeVisible(BOOL bNewValue);
	BOOL GetDisplayRightRuler();
	void SetDisplayRightRuler(BOOL bNewValue);
	BOOL GetDisplayLeftScrollBar();
	void SetDisplayLeftScrollBar(BOOL bNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// Windows wrapper class

class Windows : public COleDispatchDriver
{
public:
	Windows() {}		// Calls COleDispatchDriver default constructor
	Windows(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Windows(const Windows& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(VARIANT* Index);
	LPDISPATCH Add(VARIANT* Window);
	void Arrange(VARIANT* ArrangeStyle);
};
/////////////////////////////////////////////////////////////////////////////
// Pane wrapper class

class Pane : public COleDispatchDriver
{
public:
	Pane() {}		// Calls COleDispatchDriver default constructor
	Pane(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Pane(const Pane& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetDocument();
	LPDISPATCH GetSelection();
	BOOL GetDisplayRulers();
	void SetDisplayRulers(BOOL bNewValue);
	BOOL GetDisplayVerticalRuler();
	void SetDisplayVerticalRuler(BOOL bNewValue);
	LPDISPATCH GetZooms();
	long GetIndex();
	LPDISPATCH GetView();
	LPDISPATCH GetNext();
	LPDISPATCH GetPrevious();
	long GetHorizontalPercentScrolled();
	void SetHorizontalPercentScrolled(long nNewValue);
	long GetVerticalPercentScrolled();
	void SetVerticalPercentScrolled(long nNewValue);
	long GetMinimumFontSize();
	void SetMinimumFontSize(long nNewValue);
	long GetBrowseWidth();
	void Activate();
	void Close();
	void LargeScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft);
	void SmallScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft);
	void AutoScroll(long Velocity);
	void PageScroll(VARIANT* Down, VARIANT* Up);
	void NewFrameset();
	void TOCInFrameset();
	LPDISPATCH GetFrameset();
};
/////////////////////////////////////////////////////////////////////////////
// Panes wrapper class

class Panes : public COleDispatchDriver
{
public:
	Panes() {}		// Calls COleDispatchDriver default constructor
	Panes(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Panes(const Panes& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(VARIANT* SplitVertical);
};
/////////////////////////////////////////////////////////////////////////////
// Range wrapper class

class Range : public COleDispatchDriver
{
public:
	Range() {}		// Calls COleDispatchDriver default constructor
	Range(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Range(const Range& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	LPDISPATCH GetFormattedText();
	void SetFormattedText(LPDISPATCH newValue);
	long GetStart();
	void SetStart(long nNewValue);
	long GetEnd();
	void SetEnd(long nNewValue);
	LPDISPATCH GetFont();
	void SetFont(LPDISPATCH newValue);
	LPDISPATCH GetDuplicate();
	long GetStoryType();
	LPDISPATCH GetTables();
	LPDISPATCH GetWords();
	LPDISPATCH GetSentences();
	LPDISPATCH GetCharacters();
	LPDISPATCH GetFootnotes();
	LPDISPATCH GetEndnotes();
	LPDISPATCH GetComments();
	LPDISPATCH GetCells();
	LPDISPATCH GetSections();
	LPDISPATCH GetParagraphs();
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetShading();
	LPDISPATCH GetTextRetrievalMode();
	void SetTextRetrievalMode(LPDISPATCH newValue);
	LPDISPATCH GetFields();
	LPDISPATCH GetFormFields();
	LPDISPATCH GetFrames();
	LPDISPATCH GetParagraphFormat();
	void SetParagraphFormat(LPDISPATCH newValue);
	LPDISPATCH GetListFormat();
	LPDISPATCH GetBookmarks();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long GetBold();
	void SetBold(long nNewValue);
	long GetItalic();
	void SetItalic(long nNewValue);
	long GetUnderline();
	void SetUnderline(long nNewValue);
	long GetEmphasisMark();
	void SetEmphasisMark(long nNewValue);
	BOOL GetDisableCharacterSpaceGrid();
	void SetDisableCharacterSpaceGrid(BOOL bNewValue);
	LPDISPATCH GetRevisions();
	VARIANT GetStyle();
	void SetStyle(VARIANT* newValue);
	long GetStoryLength();
	long GetLanguageID();
	void SetLanguageID(long nNewValue);
	LPDISPATCH GetSynonymInfo();
	LPDISPATCH GetHyperlinks();
	LPDISPATCH GetListParagraphs();
	LPDISPATCH GetSubdocuments();
	BOOL GetGrammarChecked();
	void SetGrammarChecked(BOOL bNewValue);
	BOOL GetSpellingChecked();
	void SetSpellingChecked(BOOL bNewValue);
	long GetHighlightColorIndex();
	void SetHighlightColorIndex(long nNewValue);
	LPDISPATCH GetColumns();
	LPDISPATCH GetRows();
	BOOL GetIsEndOfRowMark();
	long GetBookmarkID();
	long GetPreviousBookmarkID();
	LPDISPATCH GetFind();
	LPDISPATCH GetPageSetup();
	void SetPageSetup(LPDISPATCH newValue);
	LPDISPATCH GetShapeRange();
	long GetCase();
	void SetCase(long nNewValue);
	VARIANT GetInformation(long Type);
	LPDISPATCH GetReadabilityStatistics();
	LPDISPATCH GetGrammaticalErrors();
	LPDISPATCH GetSpellingErrors();
	long GetOrientation();
	void SetOrientation(long nNewValue);
	LPDISPATCH GetInlineShapes();
	LPDISPATCH GetNextStoryRange();
	long GetLanguageIDFarEast();
	void SetLanguageIDFarEast(long nNewValue);
	long GetLanguageIDOther();
	void SetLanguageIDOther(long nNewValue);
	void Select();
	void SetRange(long Start, long End);
	void Collapse(VARIANT* Direction);
	void InsertBefore(LPCTSTR Text);
	void InsertAfter(LPCTSTR Text);
	LPDISPATCH Next(VARIANT* Unit, VARIANT* Count);
	LPDISPATCH Previous(VARIANT* Unit, VARIANT* Count);
	long StartOf(VARIANT* Unit, VARIANT* Extend);
	long EndOf(VARIANT* Unit, VARIANT* Extend);
	long Move(VARIANT* Unit, VARIANT* Count);
	long MoveStart(VARIANT* Unit, VARIANT* Count);
	long MoveEnd(VARIANT* Unit, VARIANT* Count);
	long MoveWhile(VARIANT* Cset, VARIANT* Count);
	long MoveStartWhile(VARIANT* Cset, VARIANT* Count);
	long MoveEndWhile(VARIANT* Cset, VARIANT* Count);
	long MoveUntil(VARIANT* Cset, VARIANT* Count);
	long MoveStartUntil(VARIANT* Cset, VARIANT* Count);
	long MoveEndUntil(VARIANT* Cset, VARIANT* Count);
	void Cut();
	void Copy();
	void Paste();
	void InsertBreak(VARIANT* Type);
	void InsertFile(LPCTSTR FileName, VARIANT* Range, VARIANT* ConfirmConversions, VARIANT* Link, VARIANT* Attachment);
	BOOL InStory(LPDISPATCH Range);
	BOOL InRange(LPDISPATCH Range);
	long Delete(VARIANT* Unit, VARIANT* Count);
	void WholeStory();
	long Expand(VARIANT* Unit);
	void InsertParagraph();
	void InsertParagraphAfter();
	void InsertSymbol(long CharacterNumber, VARIANT* Font, VARIANT* Unicode, VARIANT* Bias);
	void InsertCrossReference(VARIANT* ReferenceType, long ReferenceKind, VARIANT* ReferenceItem, VARIANT* InsertAsHyperlink, VARIANT* IncludePosition);
	void InsertCaption(VARIANT* Label, VARIANT* Title, VARIANT* TitleAutoText, VARIANT* Position);
	void CopyAsPicture();
	void SortAscending();
	void SortDescending();
	BOOL IsEqual(LPDISPATCH Range);
	float Calculate();
	LPDISPATCH GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name);
	LPDISPATCH GoToNext(long What);
	LPDISPATCH GoToPrevious(long What);
	void PasteSpecial(VARIANT* IconIndex, VARIANT* Link, VARIANT* Placement, VARIANT* DisplayAsIcon, VARIANT* DataType, VARIANT* IconFileName, VARIANT* IconLabel);
	void LookupNameProperties();
	long ComputeStatistics(long Statistic);
	void Relocate(long Direction);
	void CheckSynonyms();
	void SubscribeTo(LPCTSTR Edition, VARIANT* Format);
	void CreatePublisher(VARIANT* Edition, VARIANT* ContainsPICT, VARIANT* ContainsRTF, VARIANT* ContainsText);
	void InsertAutoText();
	void InsertDatabase(VARIANT* Format, VARIANT* Style, VARIANT* LinkToSource, VARIANT* Connection, VARIANT* SQLStatement, VARIANT* SQLStatement1, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* WritePasswordDocument, 
		VARIANT* WritePasswordTemplate, VARIANT* DataSource, VARIANT* From, VARIANT* To, VARIANT* IncludeFields);
	void AutoFormat();
	void CheckGrammar();
	void CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
		VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	LPDISPATCH GetSpellingSuggestions(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
		VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void InsertParagraphBefore();
	void NextSubdocument();
	void PreviousSubdocument();
	void ConvertHangulAndHanja(VARIANT* ConversionsMode, VARIANT* FastConversion, VARIANT* CheckHangulEnding, VARIANT* EnableRecentOrdering, VARIANT* CustomDictionary);
	void PasteAsNestedTable();
	void ModifyEnclosure(VARIANT* Style, VARIANT* Symbol, VARIANT* EnclosedText);
	void PhoneticGuide(LPCTSTR Text, long Alignment, long Raise, long FontSize, LPCTSTR FontName);
	void InsertDateTime(VARIANT* DateTimeFormat, VARIANT* InsertAsField, VARIANT* InsertAsFullWidth, VARIANT* DateLanguage, VARIANT* CalendarType);
	void Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
		VARIANT* SortColumn, VARIANT* Separator, VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID);
	void DetectLanguage();
	LPDISPATCH ConvertToTable(VARIANT* Separator, VARIANT* NumRows, VARIANT* NumColumns, VARIANT* InitialColumnWidth, VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, 
		VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit, VARIANT* AutoFitBehavior, VARIANT* DefaultTableBehavior);
	void TCSCConverter(long WdTCSCConverterDirection, BOOL CommonTerms, BOOL UseVariants);
	BOOL GetLanguageDetected();
	void SetLanguageDetected(BOOL bNewValue);
	float GetFitTextWidth();
	void SetFitTextWidth(float newValue);
	long GetHorizontalInVertical();
	void SetHorizontalInVertical(long nNewValue);
	long GetTwoLinesInOne();
	void SetTwoLinesInOne(long nNewValue);
	BOOL GetCombineCharacters();
	void SetCombineCharacters(BOOL bNewValue);
	long GetNoProofing();
	void SetNoProofing(long nNewValue);
	LPDISPATCH GetTopLevelTables();
	LPDISPATCH GetScripts();
	long GetCharacterWidth();
	void SetCharacterWidth(long nNewValue);
	long GetKana();
	void SetKana(long nNewValue);
	long GetBoldBi();
	void SetBoldBi(long nNewValue);
	long GetItalicBi();
	void SetItalicBi(long nNewValue);
	CString GetId();
	void SetId(LPCTSTR lpszNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// ListFormat wrapper class

class ListFormat : public COleDispatchDriver
{
public:
	ListFormat() {}		// Calls COleDispatchDriver default constructor
	ListFormat(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ListFormat(const ListFormat& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetListLevelNumber();
	void SetListLevelNumber(long nNewValue);
	LPDISPATCH GetList();
	LPDISPATCH GetListTemplate();
	long GetListValue();
	BOOL GetSingleList();
	BOOL GetSingleListTemplate();
	long GetListType();
	CString GetListString();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long CanContinuePreviousList(LPDISPATCH ListTemplate);
	void RemoveNumbers(VARIANT* NumberType);
	void ConvertNumbersToText(VARIANT* NumberType);
	long CountNumberedItems(VARIANT* NumberType, VARIANT* Level);
	void ListOutdent();
	void ListIndent();
	void ApplyBulletDefault(VARIANT* DefaultListBehavior);
	void ApplyNumberDefault(VARIANT* DefaultListBehavior);
	void ApplyOutlineNumberDefault(VARIANT* DefaultListBehavior);
	void ApplyListTemplate(LPDISPATCH ListTemplate, VARIANT* ContinuePreviousList, VARIANT* ApplyTo, VARIANT* DefaultListBehavior);
};
/////////////////////////////////////////////////////////////////////////////
// Characters wrapper class

class Characters : public COleDispatchDriver
{
public:
	Characters() {}		// Calls COleDispatchDriver default constructor
	Characters(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Characters(const Characters& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetFirst();
	LPDISPATCH GetLast();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(long Index);
};
/////////////////////////////////////////////////////////////////////////////
// Words wrapper class

class Words : public COleDispatchDriver
{
public:
	Words() {}		// Calls COleDispatchDriver default constructor
	Words(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Words(const Words& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetFirst();
	LPDISPATCH GetLast();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(long Index);
};
/////////////////////////////////////////////////////////////////////////////
// Sections wrapper class

class Sections : public COleDispatchDriver
{
public:
	Sections() {}		// Calls COleDispatchDriver default constructor
	Sections(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Sections(const Sections& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetFirst();
	LPDISPATCH GetLast();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetPageSetup();
	void SetPageSetup(LPDISPATCH newValue);
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(VARIANT* Range, VARIANT* Start);
};
/////////////////////////////////////////////////////////////////////////////
// Section wrapper class

class Section : public COleDispatchDriver
{
public:
	Section() {}		// Calls COleDispatchDriver default constructor
	Section(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Section(const Section& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetRange();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetPageSetup();
	void SetPageSetup(LPDISPATCH newValue);
	LPDISPATCH GetHeaders();
	LPDISPATCH GetFooters();
	BOOL GetProtectedForForms();
	void SetProtectedForForms(BOOL bNewValue);
	long GetIndex();
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
};
/////////////////////////////////////////////////////////////////////////////
// Paragraphs wrapper class

class Paragraphs : public COleDispatchDriver
{
public:
	Paragraphs() {}		// Calls COleDispatchDriver default constructor
	Paragraphs(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Paragraphs(const Paragraphs& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetFirst();
	LPDISPATCH GetLast();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetFormat();
	void SetFormat(LPDISPATCH newValue);
	LPDISPATCH GetTabStops();
	void SetTabStops(LPDISPATCH newValue);
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	VARIANT GetStyle();
	void SetStyle(VARIANT* newValue);
	long GetAlignment();
	void SetAlignment(long nNewValue);
	long GetKeepTogether();
	void SetKeepTogether(long nNewValue);
	long GetKeepWithNext();
	void SetKeepWithNext(long nNewValue);
	long GetPageBreakBefore();
	void SetPageBreakBefore(long nNewValue);
	long GetNoLineNumber();
	void SetNoLineNumber(long nNewValue);
	float GetRightIndent();
	void SetRightIndent(float newValue);
	float GetLeftIndent();
	void SetLeftIndent(float newValue);
	float GetFirstLineIndent();
	void SetFirstLineIndent(float newValue);
	float GetLineSpacing();
	void SetLineSpacing(float newValue);
	long GetLineSpacingRule();
	void SetLineSpacingRule(long nNewValue);
	float GetSpaceBefore();
	void SetSpaceBefore(float newValue);
	float GetSpaceAfter();
	void SetSpaceAfter(float newValue);
	long GetHyphenation();
	void SetHyphenation(long nNewValue);
	long GetWidowControl();
	void SetWidowControl(long nNewValue);
	LPDISPATCH GetShading();
	long GetFarEastLineBreakControl();
	void SetFarEastLineBreakControl(long nNewValue);
	long GetWordWrap();
	void SetWordWrap(long nNewValue);
	long GetHangingPunctuation();
	void SetHangingPunctuation(long nNewValue);
	long GetHalfWidthPunctuationOnTopOfLine();
	void SetHalfWidthPunctuationOnTopOfLine(long nNewValue);
	long GetAddSpaceBetweenFarEastAndAlpha();
	void SetAddSpaceBetweenFarEastAndAlpha(long nNewValue);
	long GetAddSpaceBetweenFarEastAndDigit();
	void SetAddSpaceBetweenFarEastAndDigit(long nNewValue);
	long GetBaseLineAlignment();
	void SetBaseLineAlignment(long nNewValue);
	long GetAutoAdjustRightIndent();
	void SetAutoAdjustRightIndent(long nNewValue);
	long GetDisableLineHeightGrid();
	void SetDisableLineHeightGrid(long nNewValue);
	long GetOutlineLevel();
	void SetOutlineLevel(long nNewValue);
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(VARIANT* Range);
	void CloseUp();
	void OpenUp();
	void OpenOrCloseUp();
	void TabHangingIndent(short Count);
	void TabIndent(short Count);
	void Reset();
	void Space1();
	void Space15();
	void Space2();
	void IndentCharWidth(short Count);
	void IndentFirstLineCharWidth(short Count);
	void OutlinePromote();
	void OutlineDemote();
	void OutlineDemoteToBody();
	void Indent();
	void Outdent();
	float GetCharacterUnitRightIndent();
	void SetCharacterUnitRightIndent(float newValue);
	float GetCharacterUnitLeftIndent();
	void SetCharacterUnitLeftIndent(float newValue);
	float GetCharacterUnitFirstLineIndent();
	void SetCharacterUnitFirstLineIndent(float newValue);
	float GetLineUnitBefore();
	void SetLineUnitBefore(float newValue);
	float GetLineUnitAfter();
	void SetLineUnitAfter(float newValue);
	long GetReadingOrder();
	void SetReadingOrder(long nNewValue);
	long GetSpaceBeforeAuto();
	void SetSpaceBeforeAuto(long nNewValue);
	long GetSpaceAfterAuto();
	void SetSpaceAfterAuto(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// Paragraph wrapper class

class Paragraph : public COleDispatchDriver
{
public:
	Paragraph() {}		// Calls COleDispatchDriver default constructor
	Paragraph(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Paragraph(const Paragraph& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetRange();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetFormat();
	void SetFormat(LPDISPATCH newValue);
	LPDISPATCH GetTabStops();
	void SetTabStops(LPDISPATCH newValue);
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetDropCap();
	VARIANT GetStyle();
	void SetStyle(VARIANT* newValue);
	long GetAlignment();
	void SetAlignment(long nNewValue);
	long GetKeepTogether();
	void SetKeepTogether(long nNewValue);
	long GetKeepWithNext();
	void SetKeepWithNext(long nNewValue);
	long GetPageBreakBefore();
	void SetPageBreakBefore(long nNewValue);
	long GetNoLineNumber();
	void SetNoLineNumber(long nNewValue);
	float GetRightIndent();
	void SetRightIndent(float newValue);
	float GetLeftIndent();
	void SetLeftIndent(float newValue);
	float GetFirstLineIndent();
	void SetFirstLineIndent(float newValue);
	float GetLineSpacing();
	void SetLineSpacing(float newValue);
	long GetLineSpacingRule();
	void SetLineSpacingRule(long nNewValue);
	float GetSpaceBefore();
	void SetSpaceBefore(float newValue);
	float GetSpaceAfter();
	void SetSpaceAfter(float newValue);
	long GetHyphenation();
	void SetHyphenation(long nNewValue);
	long GetWidowControl();
	void SetWidowControl(long nNewValue);
	LPDISPATCH GetShading();
	long GetFarEastLineBreakControl();
	void SetFarEastLineBreakControl(long nNewValue);
	long GetWordWrap();
	void SetWordWrap(long nNewValue);
	long GetHangingPunctuation();
	void SetHangingPunctuation(long nNewValue);
	long GetHalfWidthPunctuationOnTopOfLine();
	void SetHalfWidthPunctuationOnTopOfLine(long nNewValue);
	long GetAddSpaceBetweenFarEastAndAlpha();
	void SetAddSpaceBetweenFarEastAndAlpha(long nNewValue);
	long GetAddSpaceBetweenFarEastAndDigit();
	void SetAddSpaceBetweenFarEastAndDigit(long nNewValue);
	long GetBaseLineAlignment();
	void SetBaseLineAlignment(long nNewValue);
	long GetAutoAdjustRightIndent();
	void SetAutoAdjustRightIndent(long nNewValue);
	long GetDisableLineHeightGrid();
	void SetDisableLineHeightGrid(long nNewValue);
	long GetOutlineLevel();
	void SetOutlineLevel(long nNewValue);
	void CloseUp();
	void OpenUp();
	void OpenOrCloseUp();
	void TabHangingIndent(short Count);
	void TabIndent(short Count);
	void Reset();
	void Space1();
	void Space15();
	void Space2();
	void IndentCharWidth(short Count);
	void IndentFirstLineCharWidth(short Count);
	LPDISPATCH Next(VARIANT* Count);
	LPDISPATCH Previous(VARIANT* Count);
	void OutlinePromote();
	void OutlineDemote();
	void OutlineDemoteToBody();
	void Indent();
	void Outdent();
	float GetCharacterUnitRightIndent();
	void SetCharacterUnitRightIndent(float newValue);
	float GetCharacterUnitLeftIndent();
	void SetCharacterUnitLeftIndent(float newValue);
	float GetCharacterUnitFirstLineIndent();
	void SetCharacterUnitFirstLineIndent(float newValue);
	float GetLineUnitBefore();
	void SetLineUnitBefore(float newValue);
	float GetLineUnitAfter();
	void SetLineUnitAfter(float newValue);
	long GetReadingOrder();
	void SetReadingOrder(long nNewValue);
	CString GetId();
	void SetId(LPCTSTR lpszNewValue);
	long GetSpaceBeforeAuto();
	void SetSpaceBeforeAuto(long nNewValue);
	long GetSpaceAfterAuto();
	void SetSpaceAfterAuto(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// _ParagraphFormat wrapper class

class _ParagraphFormat : public COleDispatchDriver
{
public:
	_ParagraphFormat() {}		// Calls COleDispatchDriver default constructor
	_ParagraphFormat(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_ParagraphFormat(const _ParagraphFormat& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetDuplicate();
	VARIANT GetStyle();
	void SetStyle(VARIANT* newValue);
	long GetAlignment();
	void SetAlignment(long nNewValue);
	long GetKeepTogether();
	void SetKeepTogether(long nNewValue);
	long GetKeepWithNext();
	void SetKeepWithNext(long nNewValue);
	long GetPageBreakBefore();
	void SetPageBreakBefore(long nNewValue);
	long GetNoLineNumber();
	void SetNoLineNumber(long nNewValue);
	float GetRightIndent();
	void SetRightIndent(float newValue);
	float GetLeftIndent();
	void SetLeftIndent(float newValue);
	float GetFirstLineIndent();
	void SetFirstLineIndent(float newValue);
	float GetLineSpacing();
	void SetLineSpacing(float newValue);
	long GetLineSpacingRule();
	void SetLineSpacingRule(long nNewValue);
	float GetSpaceBefore();
	void SetSpaceBefore(float newValue);
	float GetSpaceAfter();
	void SetSpaceAfter(float newValue);
	long GetHyphenation();
	void SetHyphenation(long nNewValue);
	long GetWidowControl();
	void SetWidowControl(long nNewValue);
	long GetFarEastLineBreakControl();
	void SetFarEastLineBreakControl(long nNewValue);
	long GetWordWrap();
	void SetWordWrap(long nNewValue);
	long GetHangingPunctuation();
	void SetHangingPunctuation(long nNewValue);
	long GetHalfWidthPunctuationOnTopOfLine();
	void SetHalfWidthPunctuationOnTopOfLine(long nNewValue);
	long GetAddSpaceBetweenFarEastAndAlpha();
	void SetAddSpaceBetweenFarEastAndAlpha(long nNewValue);
	long GetAddSpaceBetweenFarEastAndDigit();
	void SetAddSpaceBetweenFarEastAndDigit(long nNewValue);
	long GetBaseLineAlignment();
	void SetBaseLineAlignment(long nNewValue);
	long GetAutoAdjustRightIndent();
	void SetAutoAdjustRightIndent(long nNewValue);
	long GetDisableLineHeightGrid();
	void SetDisableLineHeightGrid(long nNewValue);
	LPDISPATCH GetTabStops();
	void SetTabStops(LPDISPATCH newValue);
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetShading();
	long GetOutlineLevel();
	void SetOutlineLevel(long nNewValue);
	void CloseUp();
	void OpenUp();
	void OpenOrCloseUp();
	void TabHangingIndent(short Count);
	void TabIndent(short Count);
	void Reset();
	void Space1();
	void Space15();
	void Space2();
	void IndentCharWidth(short Count);
	void IndentFirstLineCharWidth(short Count);
	float GetCharacterUnitRightIndent();
	void SetCharacterUnitRightIndent(float newValue);
	float GetCharacterUnitLeftIndent();
	void SetCharacterUnitLeftIndent(float newValue);
	float GetCharacterUnitFirstLineIndent();
	void SetCharacterUnitFirstLineIndent(float newValue);
	float GetLineUnitBefore();
	void SetLineUnitBefore(float newValue);
	float GetLineUnitAfter();
	void SetLineUnitAfter(float newValue);
	long GetReadingOrder();
	void SetReadingOrder(long nNewValue);
	long GetSpaceBeforeAuto();
	void SetSpaceBeforeAuto(long nNewValue);
	long GetSpaceAfterAuto();
	void SetSpaceAfterAuto(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// _Font wrapper class

class _Font : public COleDispatchDriver
{
public:
	_Font() {}		// Calls COleDispatchDriver default constructor
	_Font(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Font(const _Font& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetDuplicate();
	long GetBold();
	void SetBold(long nNewValue);
	long GetItalic();
	void SetItalic(long nNewValue);
	long GetHidden();
	void SetHidden(long nNewValue);
	long GetSmallCaps();
	void SetSmallCaps(long nNewValue);
	long GetAllCaps();
	void SetAllCaps(long nNewValue);
	long GetStrikeThrough();
	void SetStrikeThrough(long nNewValue);
	long GetDoubleStrikeThrough();
	void SetDoubleStrikeThrough(long nNewValue);
	long GetColorIndex();
	void SetColorIndex(long nNewValue);
	long GetSubscript();
	void SetSubscript(long nNewValue);
	long GetSuperscript();
	void SetSuperscript(long nNewValue);
	long GetUnderline();
	void SetUnderline(long nNewValue);
	float GetSize();
	void SetSize(float newValue);
	CString GetName();
	void SetName(LPCTSTR lpszNewValue);
	long GetPosition();
	void SetPosition(long nNewValue);
	float GetSpacing();
	void SetSpacing(float newValue);
	long GetScaling();
	void SetScaling(long nNewValue);
	long GetShadow();
	void SetShadow(long nNewValue);
	long GetOutline();
	void SetOutline(long nNewValue);
	long GetEmboss();
	void SetEmboss(long nNewValue);
	float GetKerning();
	void SetKerning(float newValue);
	long GetEngrave();
	void SetEngrave(long nNewValue);
	long GetAnimation();
	void SetAnimation(long nNewValue);
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetShading();
	long GetEmphasisMark();
	void SetEmphasisMark(long nNewValue);
	BOOL GetDisableCharacterSpaceGrid();
	void SetDisableCharacterSpaceGrid(BOOL bNewValue);
	CString GetNameFarEast();
	void SetNameFarEast(LPCTSTR lpszNewValue);
	CString GetNameAscii();
	void SetNameAscii(LPCTSTR lpszNewValue);
	CString GetNameOther();
	void SetNameOther(LPCTSTR lpszNewValue);
	void Grow();
	void Shrink();
	void Reset();
	void SetAsTemplateDefault();
	long GetColor();
	void SetColor(long nNewValue);
	long GetBoldBi();
	void SetBoldBi(long nNewValue);
	long GetItalicBi();
	void SetItalicBi(long nNewValue);
	float GetSizeBi();
	void SetSizeBi(float newValue);
	CString GetNameBi();
	void SetNameBi(LPCTSTR lpszNewValue);
	long GetColorIndexBi();
	void SetColorIndexBi(long nNewValue);
	long GetDiacriticColor();
	void SetDiacriticColor(long nNewValue);
	long GetUnderlineColor();
	void SetUnderlineColor(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// LineNumbering wrapper class

class LineNumbering : public COleDispatchDriver
{
public:
	LineNumbering() {}		// Calls COleDispatchDriver default constructor
	LineNumbering(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	LineNumbering(const LineNumbering& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long GetRestartMode();
	void SetRestartMode(long nNewValue);
	long GetStartingNumber();
	void SetStartingNumber(long nNewValue);
	float GetDistanceFromText();
	void SetDistanceFromText(float newValue);
	long GetCountBy();
	void SetCountBy(long nNewValue);
	long GetActive();
	void SetActive(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// TextColumns wrapper class

class TextColumns : public COleDispatchDriver
{
public:
	TextColumns() {}		// Calls COleDispatchDriver default constructor
	TextColumns(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	TextColumns(const TextColumns& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long GetEvenlySpaced();
	void SetEvenlySpaced(long nNewValue);
	long GetLineBetween();
	void SetLineBetween(long nNewValue);
	float GetWidth();
	void SetWidth(float newValue);
	float GetSpacing();
	void SetSpacing(float newValue);
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(VARIANT* Width, VARIANT* Spacing, VARIANT* EvenlySpaced);
	void SetCount(long NumColumns);
	long GetFlowDirection();
	void SetFlowDirection(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// TextColumn wrapper class

class TextColumn : public COleDispatchDriver
{
public:
	TextColumn() {}		// Calls COleDispatchDriver default constructor
	TextColumn(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	TextColumn(const TextColumn& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	float GetWidth();
	void SetWidth(float newValue);
	float GetSpaceAfter();
	void SetSpaceAfter(float newValue);
};
/////////////////////////////////////////////////////////////////////////////
// Indexes wrapper class

class Indexes : public COleDispatchDriver
{
public:
	Indexes() {}		// Calls COleDispatchDriver default constructor
	Indexes(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Indexes(const Indexes& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	long GetFormat();
	void SetFormat(long nNewValue);
	LPDISPATCH Item(long Index);
	LPDISPATCH MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* CrossReference, VARIANT* CrossReferenceAutoText, VARIANT* BookmarkName, VARIANT* Bold, VARIANT* Italic, VARIANT* Reading);
	void MarkAllEntries(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* CrossReference, VARIANT* CrossReferenceAutoText, VARIANT* BookmarkName, VARIANT* Bold, VARIANT* Italic);
	void AutoMarkEntries(LPCTSTR ConcordanceFileName);
	LPDISPATCH Add(LPDISPATCH Range, VARIANT* HeadingSeparator, VARIANT* RightAlignPageNumbers, VARIANT* Type, VARIANT* NumberOfColumns, VARIANT* AccentedLetters, VARIANT* SortBy, VARIANT* IndexLanguage);
};
/////////////////////////////////////////////////////////////////////////////
// Index wrapper class

class Index : public COleDispatchDriver
{
public:
	Index() {}		// Calls COleDispatchDriver default constructor
	Index(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Index(const Index& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long GetHeadingSeparator();
	void SetHeadingSeparator(long nNewValue);
	BOOL GetRightAlignPageNumbers();
	void SetRightAlignPageNumbers(BOOL bNewValue);
	long GetType();
	void SetType(long nNewValue);
	long GetNumberOfColumns();
	void SetNumberOfColumns(long nNewValue);
	LPDISPATCH GetRange();
	long GetTabLeader();
	void SetTabLeader(long nNewValue);
	BOOL GetAccentedLetters();
	void SetAccentedLetters(BOOL bNewValue);
	long GetSortBy();
	void SetSortBy(long nNewValue);
	long GetFilter();
	void SetFilter(long nNewValue);
	void Delete();
	void Update();
	long GetIndexLanguage();
	void SetIndexLanguage(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// PageNumbers wrapper class

class PageNumbers : public COleDispatchDriver
{
public:
	PageNumbers() {}		// Calls COleDispatchDriver default constructor
	PageNumbers(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	PageNumbers(const PageNumbers& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	long GetNumberStyle();
	void SetNumberStyle(long nNewValue);
	BOOL GetIncludeChapterNumber();
	void SetIncludeChapterNumber(BOOL bNewValue);
	long GetHeadingLevelForChapter();
	void SetHeadingLevelForChapter(long nNewValue);
	long GetChapterPageSeparator();
	void SetChapterPageSeparator(long nNewValue);
	BOOL GetRestartNumberingAtSection();
	void SetRestartNumberingAtSection(BOOL bNewValue);
	long GetStartingNumber();
	void SetStartingNumber(long nNewValue);
	BOOL GetShowFirstPageNumber();
	void SetShowFirstPageNumber(BOOL bNewValue);
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(VARIANT* PageNumberAlignment, VARIANT* FirstPage);
	BOOL GetDoubleQuote();
	void SetDoubleQuote(BOOL bNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// PageNumber wrapper class

class PageNumber : public COleDispatchDriver
{
public:
	PageNumber() {}		// Calls COleDispatchDriver default constructor
	PageNumber(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	PageNumber(const PageNumber& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long GetIndex();
	long GetAlignment();
	void SetAlignment(long nNewValue);
	void Select();
	void Copy();
	void Cut();
	void Delete();
};
/////////////////////////////////////////////////////////////////////////////
// List wrapper class

class List : public COleDispatchDriver
{
public:
	List() {}		// Calls COleDispatchDriver default constructor
	List(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	List(const List& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetRange();
	LPDISPATCH GetListParagraphs();
	BOOL GetSingleListTemplate();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	void ConvertNumbersToText(VARIANT* NumberType);
	void RemoveNumbers(VARIANT* NumberType);
	long CountNumberedItems(VARIANT* NumberType, VARIANT* Level);
	long CanContinuePreviousList(LPDISPATCH ListTemplate);
	void ApplyListTemplate(LPDISPATCH ListTemplate, VARIANT* ContinuePreviousList, VARIANT* DefaultListBehavior);
};
/////////////////////////////////////////////////////////////////////////////
// Lists wrapper class

class Lists : public COleDispatchDriver
{
public:
	Lists() {}		// Calls COleDispatchDriver default constructor
	Lists(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Lists(const Lists& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(long Index);
};
/////////////////////////////////////////////////////////////////////////////
// ListGallery wrapper class

class ListGallery : public COleDispatchDriver
{
public:
	ListGallery() {}		// Calls COleDispatchDriver default constructor
	ListGallery(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ListGallery(const ListGallery& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetListTemplates();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	BOOL GetModified(long Index);
	void Reset(long Index);
};
/////////////////////////////////////////////////////////////////////////////
// ListGalleries wrapper class

class ListGalleries : public COleDispatchDriver
{
public:
	ListGalleries() {}		// Calls COleDispatchDriver default constructor
	ListGalleries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ListGalleries(const ListGalleries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(long Index);
};
/////////////////////////////////////////////////////////////////////////////
// Dictionary wrapper class

class Dictionary : public COleDispatchDriver
{
public:
	Dictionary() {}		// Calls COleDispatchDriver default constructor
	Dictionary(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Dictionary(const Dictionary& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetName();
	CString GetPath();
	long GetLanguageID();
	void SetLanguageID(long nNewValue);
	BOOL GetReadOnly();
	long GetType();
	BOOL GetLanguageSpecific();
	void SetLanguageSpecific(BOOL bNewValue);
	void Delete();
};
/////////////////////////////////////////////////////////////////////////////
// Styles wrapper class

class Styles : public COleDispatchDriver
{
public:
	Styles() {}		// Calls COleDispatchDriver default constructor
	Styles(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Styles(const Styles& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH Item(VARIANT* Index);
	LPDISPATCH Add(LPCTSTR Name, VARIANT* Type);
};
/////////////////////////////////////////////////////////////////////////////
// Style wrapper class

class Style : public COleDispatchDriver
{
public:
	Style() {}		// Calls COleDispatchDriver default constructor
	Style(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Style(const Style& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetNameLocal();
	void SetNameLocal(LPCTSTR lpszNewValue);
	VARIANT GetBaseStyle();
	void SetBaseStyle(VARIANT* newValue);
	CString GetDescription();
	long GetType();
	BOOL GetBuiltIn();
	VARIANT GetNextParagraphStyle();
	void SetNextParagraphStyle(VARIANT* newValue);
	BOOL GetInUse();
	LPDISPATCH GetShading();
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetParagraphFormat();
	void SetParagraphFormat(LPDISPATCH newValue);
	LPDISPATCH GetFont();
	void SetFont(LPDISPATCH newValue);
	LPDISPATCH GetFrame();
	long GetLanguageID();
	void SetLanguageID(long nNewValue);
	BOOL GetAutomaticallyUpdate();
	void SetAutomaticallyUpdate(BOOL bNewValue);
	LPDISPATCH GetListTemplate();
	long GetListLevelNumber();
	long GetLanguageIDFarEast();
	void SetLanguageIDFarEast(long nNewValue);
	void Delete();
	void LinkToListTemplate(LPDISPATCH ListTemplate, VARIANT* ListLevelNumber);
	long GetNoProofing();
	void SetNoProofing(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// HeadingStyles wrapper class

class HeadingStyles : public COleDispatchDriver
{
public:
	HeadingStyles() {}		// Calls COleDispatchDriver default constructor
	HeadingStyles(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	HeadingStyles(const HeadingStyles& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(VARIANT* Style, short Level);
};
/////////////////////////////////////////////////////////////////////////////
// HeadingStyle wrapper class

class HeadingStyle : public COleDispatchDriver
{
public:
	HeadingStyle() {}		// Calls COleDispatchDriver default constructor
	HeadingStyle(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	HeadingStyle(const HeadingStyle& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	VARIANT GetStyle();
	void SetStyle(VARIANT* newValue);
	short GetLevel();
	void SetLevel(short nNewValue);
	void Delete();
};
/////////////////////////////////////////////////////////////////////////////
// Table wrapper class

class Table : public COleDispatchDriver
{
public:
	Table() {}		// Calls COleDispatchDriver default constructor
	Table(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Table(const Table& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetRange();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetColumns();
	LPDISPATCH GetRows();
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetShading();
	BOOL GetUniform();
	long GetAutoFormatType();
	void Select();
	void Delete();
	void SortAscending();
	void SortDescending();
	void AutoFormat(VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit);
	void UpdateAutoFormat();
	LPDISPATCH Cell(long Row, long Column);
	LPDISPATCH Split(VARIANT* BeforeRow);
	LPDISPATCH ConvertToText(VARIANT* Separator, VARIANT* NestedTables);
	void AutoFitBehavior(long Behavior);
	void Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
		VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID);
	LPDISPATCH GetTables();
	long GetNestingLevel();
	BOOL GetAllowPageBreaks();
	void SetAllowPageBreaks(BOOL bNewValue);
	BOOL GetAllowAutoFit();
	void SetAllowAutoFit(BOOL bNewValue);
	float GetPreferredWidth();
	void SetPreferredWidth(float newValue);
	long GetPreferredWidthType();
	void SetPreferredWidthType(long nNewValue);
	float GetTopPadding();
	void SetTopPadding(float newValue);
	float GetBottomPadding();
	void SetBottomPadding(float newValue);
	float GetLeftPadding();
	void SetLeftPadding(float newValue);
	float GetRightPadding();
	void SetRightPadding(float newValue);
	float GetSpacing();
	void SetSpacing(float newValue);
	long GetTableDirection();
	void SetTableDirection(long nNewValue);
	CString GetId();
	void SetId(LPCTSTR lpszNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// Tables wrapper class

class Tables : public COleDispatchDriver
{
public:
	Tables() {}		// Calls COleDispatchDriver default constructor
	Tables(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Tables(const Tables& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(LPDISPATCH Range, long NumRows, long NumColumns, VARIANT* DefaultTableBehavior, VARIANT* AutoFitBehavior);
	long GetNestingLevel();
};
/////////////////////////////////////////////////////////////////////////////
// TablesOfFigures wrapper class

class TablesOfFigures : public COleDispatchDriver
{
public:
	TablesOfFigures() {}		// Calls COleDispatchDriver default constructor
	TablesOfFigures(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	TablesOfFigures(const TablesOfFigures& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	long GetFormat();
	void SetFormat(long nNewValue);
	LPDISPATCH Item(long Index);
	LPDISPATCH MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* TableID, VARIANT* Level);
	LPDISPATCH Add(LPDISPATCH Range, VARIANT* Caption, VARIANT* IncludeLabel, VARIANT* UseHeadingStyles, VARIANT* UpperHeadingLevel, VARIANT* LowerHeadingLevel, VARIANT* UseFields, VARIANT* TableID, VARIANT* RightAlignPageNumbers, 
		VARIANT* IncludePageNumbers, VARIANT* AddedStyles, VARIANT* UseHyperlinks, VARIANT* HidePageNumbersInWeb);
};
/////////////////////////////////////////////////////////////////////////////
// TableOfFigures wrapper class

class TableOfFigures : public COleDispatchDriver
{
public:
	TableOfFigures() {}		// Calls COleDispatchDriver default constructor
	TableOfFigures(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	TableOfFigures(const TableOfFigures& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	BOOL GetIncludeLabel();
	void SetIncludeLabel(BOOL bNewValue);
	BOOL GetRightAlignPageNumbers();
	void SetRightAlignPageNumbers(BOOL bNewValue);
	BOOL GetUseHeadingStyles();
	void SetUseHeadingStyles(BOOL bNewValue);
	long GetLowerHeadingLevel();
	void SetLowerHeadingLevel(long nNewValue);
	long GetUpperHeadingLevel();
	void SetUpperHeadingLevel(long nNewValue);
	BOOL GetIncludePageNumbers();
	void SetIncludePageNumbers(BOOL bNewValue);
	LPDISPATCH GetRange();
	BOOL GetUseFields();
	void SetUseFields(BOOL bNewValue);
	CString GetTableID();
	void SetTableID(LPCTSTR lpszNewValue);
	LPDISPATCH GetHeadingStyles();
	long GetTabLeader();
	void SetTabLeader(long nNewValue);
	void Delete();
	void UpdatePageNumbers();
	void Update();
	BOOL GetUseHyperlinks();
	void SetUseHyperlinks(BOOL bNewValue);
	BOOL GetHidePageNumbersInWeb();
	void SetHidePageNumbersInWeb(BOOL bNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// TablesOfContents wrapper class

class TablesOfContents : public COleDispatchDriver
{
public:
	TablesOfContents() {}		// Calls COleDispatchDriver default constructor
	TablesOfContents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	TablesOfContents(const TablesOfContents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	long GetFormat();
	void SetFormat(long nNewValue);
	LPDISPATCH Item(long Index);
	LPDISPATCH MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* TableID, VARIANT* Level);
	LPDISPATCH Add(LPDISPATCH Range, VARIANT* UseHeadingStyles, VARIANT* UpperHeadingLevel, VARIANT* LowerHeadingLevel, VARIANT* UseFields, VARIANT* TableID, VARIANT* RightAlignPageNumbers, VARIANT* IncludePageNumbers, VARIANT* AddedStyles, 
		VARIANT* UseHyperlinks, VARIANT* HidePageNumbersInWeb);
};
/////////////////////////////////////////////////////////////////////////////
// TableOfContents wrapper class

class TableOfContents : public COleDispatchDriver
{
public:
	TableOfContents() {}		// Calls COleDispatchDriver default constructor
	TableOfContents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	TableOfContents(const TableOfContents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	BOOL GetUseHeadingStyles();
	void SetUseHeadingStyles(BOOL bNewValue);
	BOOL GetUseFields();
	void SetUseFields(BOOL bNewValue);
	long GetUpperHeadingLevel();
	void SetUpperHeadingLevel(long nNewValue);
	long GetLowerHeadingLevel();
	void SetLowerHeadingLevel(long nNewValue);
	CString GetTableID();
	void SetTableID(LPCTSTR lpszNewValue);
	LPDISPATCH GetHeadingStyles();
	BOOL GetRightAlignPageNumbers();
	void SetRightAlignPageNumbers(BOOL bNewValue);
	BOOL GetIncludePageNumbers();
	void SetIncludePageNumbers(BOOL bNewValue);
	LPDISPATCH GetRange();
	long GetTabLeader();
	void SetTabLeader(long nNewValue);
	void Delete();
	void UpdatePageNumbers();
	void Update();
	BOOL GetUseHyperlinks();
	void SetUseHyperlinks(BOOL bNewValue);
	BOOL GetHidePageNumbersInWeb();
	void SetHidePageNumbersInWeb(BOOL bNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// CaptionLabels wrapper class

class CaptionLabels : public COleDispatchDriver
{
public:
	CaptionLabels() {}		// Calls COleDispatchDriver default constructor
	CaptionLabels(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CaptionLabels(const CaptionLabels& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH Item(VARIANT* Index);
	LPDISPATCH Add(LPCTSTR Name);
};
/////////////////////////////////////////////////////////////////////////////
// CaptionLabel wrapper class

class CaptionLabel : public COleDispatchDriver
{
public:
	CaptionLabel() {}		// Calls COleDispatchDriver default constructor
	CaptionLabel(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CaptionLabel(const CaptionLabel& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetName();
	BOOL GetBuiltIn();
	long GetId();
	BOOL GetIncludeChapterNumber();
	void SetIncludeChapterNumber(BOOL bNewValue);
	long GetNumberStyle();
	void SetNumberStyle(long nNewValue);
	long GetChapterStyleLevel();
	void SetChapterStyleLevel(long nNewValue);
	long GetSeparator();
	void SetSeparator(long nNewValue);
	long GetPosition();
	void SetPosition(long nNewValue);
	void Delete();
};
/////////////////////////////////////////////////////////////////////////////
// AutoCaptions wrapper class

class AutoCaptions : public COleDispatchDriver
{
public:
	AutoCaptions() {}		// Calls COleDispatchDriver default constructor
	AutoCaptions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	AutoCaptions(const AutoCaptions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH Item(VARIANT* Index);
	void CancelAutoInsert();
};
/////////////////////////////////////////////////////////////////////////////
// AutoCaption wrapper class

class AutoCaption : public COleDispatchDriver
{
public:
	AutoCaption() {}		// Calls COleDispatchDriver default constructor
	AutoCaption(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	AutoCaption(const AutoCaption& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetName();
	BOOL GetAutoInsert();
	void SetAutoInsert(BOOL bNewValue);
	long GetIndex();
	VARIANT GetCaptionLabel();
	void SetCaptionLabel(VARIANT* newValue);
};
