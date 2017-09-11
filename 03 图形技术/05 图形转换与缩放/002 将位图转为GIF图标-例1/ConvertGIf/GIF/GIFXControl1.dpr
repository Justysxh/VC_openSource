library GIFXControl1;

uses
  ComServ,
  GIFXControl1_TLB in 'GIFXControl1_TLB.pas',
  GIFImpl1 in 'GIFImpl1.pas' {GIF: CoClass};

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
