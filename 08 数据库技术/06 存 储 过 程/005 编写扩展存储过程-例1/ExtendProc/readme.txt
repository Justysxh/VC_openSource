=========================================================================
       DYNAMIC LINK LIBRARY : EXTENDPROC
========================================================================


AppWizard has created EXTENDPROC.dll for you.  

This file contains a summary of what you will find in each of the files that
make up your EXTENDPROC application.

EXTENDPROC.cpp
    This is the main dll source file.

proc.cpp
	This file contains the stored procedure xp

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named EXTENDPROC.pch and a precompiled types file named StdAfx.obj.


/////////////////////////////////////////////////////////////////////////////
Other notes:

After completing this Wizard, copy the EXTENDPROC.dll over to your SQL Server 
\Binn directory.

Add your new Extended Stored Procedure from a Visual Studio Data Project, 
or using the SQL Server Enterprise Manager, or by executing the following 
SQL command:
  sp_addextendedproc 'xp', 'EXTENDPROC.DLL'

You may drop the extended stored procedure by using the SQL command:
  sp_dropextendedproc 'xp'

You may release the DLL from the Server (to delete or replace the file), by 
using the SQL command:
  DBCC xp(FREE)


/////////////////////////////////////////////////////////////////////////////
