// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _ObjectFrame wrapper class

class _ObjectFrame : public COleDispatchDriver
{
public:
	_ObjectFrame() {}		// Calls COleDispatchDriver default constructor
	_ObjectFrame(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_ObjectFrame(const _ObjectFrame& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	LPDISPATCH GetParent();
	VARIANT GetOldValue();
	LPDISPATCH GetObject();
	CString GetObjectVerbs(long Index);
	LPDISPATCH GetProperties();
	void SizeToFit();
	void Requery();
	void SetFocus();
	LPDISPATCH GetControls();
	CString GetEventProcPrefix();
	void SetEventProcPrefix(LPCTSTR lpszNewValue);
	// method 'GetControlType' not emitted because of invalid return type or parameter type
	// method 'SetControlType' not emitted because of invalid return type or parameter type
	// method 'GetSizeMode' not emitted because of invalid return type or parameter type
	// method 'SetSizeMode' not emitted because of invalid return type or parameter type
	CString GetOLEClass();
	void SetOLEClass(LPCTSTR lpszNewValue);
	CString GetItem();
	void SetItem(LPCTSTR lpszNewValue);
	CString GetRowSourceType();
	void SetRowSourceType(LPCTSTR lpszNewValue);
	CString GetRowSource();
	void SetRowSource(LPCTSTR lpszNewValue);
	CString GetLinkChildFields();
	void SetLinkChildFields(LPCTSTR lpszNewValue);
	CString GetLinkMasterFields();
	void SetLinkMasterFields(LPCTSTR lpszNewValue);
	short GetAutoActivate();
	void SetAutoActivate(short nNewValue);
	BOOL GetDisplayType();
	void SetDisplayType(BOOL bNewValue);
	short GetUpdateOptions();
	void SetUpdateOptions(short nNewValue);
	long GetVerb();
	void SetVerb(long nNewValue);
	// method 'GetOLEType' not emitted because of invalid return type or parameter type
	// method 'SetOLEType' not emitted because of invalid return type or parameter type
	// method 'GetOLETypeAllowed' not emitted because of invalid return type or parameter type
	// method 'SetOLETypeAllowed' not emitted because of invalid return type or parameter type
	CString GetSourceObject();
	void SetSourceObject(LPCTSTR lpszNewValue);
	CString GetClass();
	void SetClass(LPCTSTR lpszNewValue);
	CString GetSourceDoc();
	void SetSourceDoc(LPCTSTR lpszNewValue);
	CString GetSourceItem();
	void SetSourceItem(LPCTSTR lpszNewValue);
	short GetColumnCount();
	void SetColumnCount(short nNewValue);
	BOOL GetColumnHeads();
	void SetColumnHeads(BOOL bNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	// method 'GetDisplayWhen' not emitted because of invalid return type or parameter type
	// method 'SetDisplayWhen' not emitted because of invalid return type or parameter type
	short GetUpdateMethod();
	void SetUpdateMethod(short nNewValue);
	BOOL GetEnabled();
	void SetEnabled(BOOL bNewValue);
	BOOL GetLocked();
	void SetLocked(BOOL bNewValue);
	CString GetStatusBarText();
	void SetStatusBarText(LPCTSTR lpszNewValue);
	BOOL GetTabStop();
	void SetTabStop(BOOL bNewValue);
	short GetTabIndex();
	void SetTabIndex(short nNewValue);
	short GetLeft();
	void SetLeft(short nNewValue);
	short GetTop();
	void SetTop(short nNewValue);
	short GetWidth();
	void SetWidth(short nNewValue);
	short GetHeight();
	void SetHeight(short nNewValue);
	// method 'GetBackStyle' not emitted because of invalid return type or parameter type
	// method 'SetBackStyle' not emitted because of invalid return type or parameter type
	long GetBackColor();
	void SetBackColor(long nNewValue);
	// method 'GetSpecialEffect' not emitted because of invalid return type or parameter type
	// method 'SetSpecialEffect' not emitted because of invalid return type or parameter type
	// method 'GetBorderStyle' not emitted because of invalid return type or parameter type
	// method 'SetBorderStyle' not emitted because of invalid return type or parameter type
	// method 'GetOldBorderStyle' not emitted because of invalid return type or parameter type
	// method 'SetOldBorderStyle' not emitted because of invalid return type or parameter type
	long GetBorderColor();
	void SetBorderColor(long nNewValue);
	// method 'GetBorderWidth' not emitted because of invalid return type or parameter type
	// method 'SetBorderWidth' not emitted because of invalid return type or parameter type
	CString GetShortcutMenuBar();
	void SetShortcutMenuBar(LPCTSTR lpszNewValue);
	CString GetControlTipText();
	void SetControlTipText(LPCTSTR lpszNewValue);
	long GetHelpContextId();
	void SetHelpContextId(long nNewValue);
	short GetSection();
	void SetSection(short nNewValue);
	CString GetTag();
	void SetTag(LPCTSTR lpszNewValue);
	VARIANT GetObjectPalette();
	void SetObjectPalette(const VARIANT& newValue);
	long GetLpOleObject();
	void SetLpOleObject(long nNewValue);
	long GetObjectVerbsCount();
	void SetObjectVerbsCount(long nNewValue);
	short GetAction();
	void SetAction(short nNewValue);
	// method 'GetScaling' not emitted because of invalid return type or parameter type
	// method 'SetScaling' not emitted because of invalid return type or parameter type
	BOOL GetIsVisible();
	void SetIsVisible(BOOL bNewValue);
	BOOL GetInSelection();
	void SetInSelection(BOOL bNewValue);
	CString GetOnUpdated();
	void SetOnUpdated(LPCTSTR lpszNewValue);
	CString GetOnEnter();
	void SetOnEnter(LPCTSTR lpszNewValue);
	CString GetOnExit();
	void SetOnExit(LPCTSTR lpszNewValue);
	CString GetOnGotFocus();
	void SetOnGotFocus(LPCTSTR lpszNewValue);
	CString GetOnLostFocus();
	void SetOnLostFocus(LPCTSTR lpszNewValue);
	CString GetOnClick();
	void SetOnClick(LPCTSTR lpszNewValue);
	CString GetOnDblClick();
	void SetOnDblClick(LPCTSTR lpszNewValue);
	CString GetOnMouseDown();
	void SetOnMouseDown(LPCTSTR lpszNewValue);
	CString GetOnMouseMove();
	void SetOnMouseMove(LPCTSTR lpszNewValue);
	CString GetOnMouseUp();
	void SetOnMouseUp(LPCTSTR lpszNewValue);
	CString GetName();
	void SetName(LPCTSTR lpszNewValue);
};
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
	LPDISPATCH GetParent();
	LPDISPATCH GetCodeContextObject();
	void NewCurrentDatabase(LPCTSTR filepath);
	void OpenCurrentDatabase(LPCTSTR filepath, BOOL Exclusive);
	CString GetMenuBar();
	void SetMenuBar(LPCTSTR lpszNewValue);
	long GetCurrentObjectType();
	CString GetCurrentObjectName();
	VARIANT GetOption(LPCTSTR OptionName);
	void SetOption(LPCTSTR OptionName, const VARIANT& Setting);
	void Echo(short EchoOn, LPCTSTR bstrStatusBarText);
	void CloseCurrentDatabase();
	void Quit(long Option);
	LPDISPATCH GetForms();
	LPDISPATCH GetReports();
	LPDISPATCH GetScreen();
	LPDISPATCH GetDoCmd();
	CString GetShortcutMenuBar();
	void SetShortcutMenuBar(LPCTSTR lpszNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	BOOL GetUserControl();
	void SetUserControl(BOOL bNewValue);
	VARIANT SysCmd(long Action, const VARIANT& Argument2, const VARIANT& Argument3);
	LPDISPATCH CreateForm(const VARIANT& Database, const VARIANT& FormTemplate);
	LPDISPATCH CreateReport(const VARIANT& Database, const VARIANT& ReportTemplate);
	LPDISPATCH CreateControl(LPCTSTR FormName, long ControlType, long Section, const VARIANT& Parent, const VARIANT& ColumnName, const VARIANT& Left, const VARIANT& Top, const VARIANT& Width, const VARIANT& Height);
	LPDISPATCH CreateReportControl(LPCTSTR ReportName, long ControlType, long Section, const VARIANT& Parent, const VARIANT& ColumnName, const VARIANT& Left, const VARIANT& Top, const VARIANT& Width, const VARIANT& Height);
	void DeleteControl(LPCTSTR FormName, LPCTSTR ControlName);
	void DeleteReportControl(LPCTSTR ReportName, LPCTSTR ControlName);
	long CreateGroupLevel(LPCTSTR ReportName, LPCTSTR Expression, short Header, short Footer);
	VARIANT DMin(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DMax(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DSum(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DAvg(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DLookup(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DLast(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DVar(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DVarP(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DStDev(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DStDevP(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DFirst(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT DCount(LPCTSTR Expr, LPCTSTR Domain, const VARIANT& Criteria);
	VARIANT Eval(LPCTSTR StringExpr);
	CString CurrentUser();
	VARIANT DDEInitiate(LPCTSTR Application, LPCTSTR Topic);
	void DDEExecute(const VARIANT& ChanNum, LPCTSTR Command);
	void DDEPoke(const VARIANT& ChanNum, LPCTSTR Item, LPCTSTR Data);
	CString DDERequest(const VARIANT& ChanNum, LPCTSTR Item);
	void DDETerminate(const VARIANT& ChanNum);
	void DDETerminateAll();
	LPDISPATCH GetDBEngine();
	LPDISPATCH CurrentDb();
	LPDISPATCH CodeDb();
	CString BuildCriteria(LPCTSTR Field, short FieldType, LPCTSTR Expression);
	LPDISPATCH DefaultWorkspaceClone();
	void RefreshTitleBar();
	long hWndAccessApp();
	VARIANT Run(LPCTSTR Procedure, VARIANT* Arg1, VARIANT* Arg2, VARIANT* Arg3, VARIANT* Arg4, VARIANT* Arg5, VARIANT* Arg6, VARIANT* Arg7, VARIANT* Arg8, VARIANT* Arg9, VARIANT* Arg10, VARIANT* Arg11, VARIANT* Arg12, VARIANT* Arg13, 
		VARIANT* Arg14, VARIANT* Arg15, VARIANT* Arg16, VARIANT* Arg17, VARIANT* Arg18, VARIANT* Arg19, VARIANT* Arg20, VARIANT* Arg21, VARIANT* Arg22, VARIANT* Arg23, VARIANT* Arg24, VARIANT* Arg25, VARIANT* Arg26, VARIANT* Arg27, 
		VARIANT* Arg28, VARIANT* Arg29, VARIANT* Arg30);
	VARIANT Nz(const VARIANT& Value, const VARIANT& ValueIfNull);
	LPDISPATCH LoadPicture(LPCTSTR FileName);
	VARIANT AccessError(const VARIANT& ErrorNumber);
	VARIANT StringFromGUID(const VARIANT& Guid);
	VARIANT GUIDFromString(const VARIANT& String);
	LPDISPATCH GetCommandBars();
	LPDISPATCH GetAssistant();
	void FollowHyperlink(LPCTSTR Address, LPCTSTR SubAddress, BOOL NewWindow, BOOL AddHistory, const VARIANT& ExtraInfo, long Method, LPCTSTR HeaderInfo);
	void AddToFavorites();
	void RefreshDatabaseWindow();
	LPDISPATCH GetReferences();
	LPDISPATCH GetModules();
	LPDISPATCH GetFileSearch();
	BOOL GetIsCompiled();
	void RunCommand(long Command);
	CString HyperlinkPart(const VARIANT& Hyperlink, long Part);
	BOOL GetHiddenAttribute(long ObjectType, LPCTSTR ObjectName);
	void SetHiddenAttribute(long ObjectType, LPCTSTR ObjectName, BOOL fHidden);
	LPDISPATCH GetVbe();
	LPDISPATCH GetDataAccessPages();
	LPDISPATCH CreateDataAccessPage(const VARIANT& FileName, BOOL CreateNewFile);
	LPDISPATCH GetCurrentProject();
	LPDISPATCH GetCurrentData();
	LPDISPATCH GetCodeProject();
	LPDISPATCH GetCodeData();
	void NewAccessProject(LPCTSTR filepath, const VARIANT& Connect);
	void OpenAccessProject(LPCTSTR filepath, BOOL Exclusive);
	void CreateAccessProject(LPCTSTR filepath, const VARIANT& Connect);
	CString GetProductCode();
	LPDISPATCH GetCOMAddIns();
	CString GetName();
	LPDISPATCH GetDefaultWebOptions();
	LPDISPATCH GetLanguageSettings();
	LPDISPATCH GetAnswerWizard();
	long GetFeatureInstall();
	void SetFeatureInstall(long nNewValue);
	double EuroConvert(double Number, LPCTSTR SourceCurrency, LPCTSTR TargetCurrency, const VARIANT& FullPrecision, const VARIANT& TriangulationPrecision);
};
