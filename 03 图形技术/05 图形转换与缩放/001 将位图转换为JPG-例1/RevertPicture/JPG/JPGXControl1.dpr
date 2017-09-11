library JPGXControl1;

uses
  ComServ,
  JPGXControl1_TLB in 'JPGXControl1_TLB.pas',
  JPGImpl1 in 'JPGImpl1.pas' {JPG: CoClass};

{$E ocx}

exports
  DllGetClassObject,
  DllCanUnloadNow,
  DllRegisterServer,
  DllUnregisterServer;

{$R *.TLB}

{$R *.RES}

begin
end.
