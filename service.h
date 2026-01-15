#ifndef SERVICE_H
#define SERVICE_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPalette>
#include <QVector>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#define waitvacswoff    200
#define waitvacnext     100
#define axesstep        50
// senddata
#define FALSE       0
#define TRUE        1
#define CRLF          "\r\n"
#define TSmode      "$TS5go\r"                // Servicemode freischalten
#define svcgetvac   "$GET_40\r\n"           // Service GET vac getoutlist
#define svcgetmm    "$GET_41\r\n"           // Service Materialliste holen
#define svcget50    "$GET_50\r\n"           // Service GET Byte PIN C
#define svcget51    "$GET_51\r\n"           // Service GET Byte DDR C
#define svcget52    "$GET_52\r\n"           // Service GET Byte PORT C
#define svcmode     "$SET_6=1\r\n"            // Servicemode für erweiterte Messages
#define svcmodeOff  "$SET_6=0\r\n"            // Servicemode für erweiterte Messages
#define debuglogoff "$SET_7=0\r\n"          // schaltet debug log aus
#define debuglogon  "$SET_7=1\r\n"          // schaltet debug log an
#define setpos      "$SET_"                   // Kategorie $SET_cmd [40, 50 - 62] s.Excel GUI
#define PSET_1    "$PSET_1=0\r\n"           // Ruft EEPROM INSSETUP Routine in der Box auf
#define SET_EE_STR  "$PSET_1=40\r\n"          // Ruft EEPROM EE_SETUP_STR() Routine in der Box auf
#define INSMOTSETUP "$PSET_1=50\r\n"          // Ruft EEPROM INSMOTOR Routine in der Box auf
#define MOTEEUPDATE "$PSET_1="                // EEPROM-Update für MOTOR n
#define EE_SETLIFT1 "$PSET_1=1\r\n"           // Ruft EEPROM Routine für Lift1
#define EE_SETLIFT2 "$PSET_1=2\r\n"           // Ruft EEPROM Routine für Lift2
#define EE_SETCASS  "$PSET_1=3\r\n"           // Ruft EEPROM Routine für Cass1
#define INSSETUPOK  "$PSET_RET=0\r\n"         // Rückmeldung vom PC bei fehlerfreier Übertragung
#define EEPDATA0    "$PSET_1="                // für Teil-Datensatz EEPROM
#define INSSETUPERR "$PSET_RET=-1"
#define BoxResRAC   "$SET_2=1\r\n"           // löst Box Reset nur RAC Controller aus
#define callsync    "$SET_90="               // setzt Node und ruft sync() auf
#define fifologoff  "$SET_98=0\r\n"          // schaltet counter log aus
#define fifologon   "$SET_98=1\r\n"          // schaltet counter log an
#define counteroff  "$SET_99=0\r\n"          // schaltet counter log aus
#define counteron   "$SET_99=1\r\n"          // schaltet counter log an
#define polloff     "$SET_100=0\r\n"         // schaltet Polling aus
#define pollon      "$SET_100=1\r\n"         // schaltet Polling an
#define resInitMot  "$SET_4=1\r\n"           // set EEMOTDATOK=0 -> initMotDat() wird ausgeführt
#define simulON     "$SET_5=1\r\n"           // Simulationsmodus an
#define simulOFF    "$SET_5=0\r\n"           // Simulationsmodus aus
#define apimode     "$SET_6=0\r\n"           // APImode für reduzierte Messages
#define warnlogon   "$SET_8=1\r\n"           // loglevel warn on
#define warnlogoff  "$SET_8=0\r\n"           // loglevel warn off
#define errorlogon  "$SET_9=1\r\n"           // loglevel error on
#define errorlogoff "$SET_9=0\r\n"           // loglevel error off
#define smiflogon   "$SET_18=1\r\n"          // SMIF log on
#define smiflogoff  "$SET_18=0\r\n"          // SMIF log off
#define smifpollon   "$SET_26=1\r\n"         // SMIF poll status on
#define smifpolloff  "$SET_26=0\r\n"         // SMIF poll status off
#define simucnton   "$SET_15=1\r\n"          // simucounter on
#define simucntoff  "$SET_15=0\r\n"          // simucounter off
#define mainvacflagon   "$SET_16=1\r\n"      // mainvacflag on für debugzwecke
#define mainvacflagoff  "$SET_16=0\r\n"      // mainvacflag off für debugzwecke
#define towerHorn   "$SET_20="               // set Tower Horn
#define towerRed    "$SET_23="               // set Tower Red
#define towerYellow "$SET_22="               // set Tower Yellow
#define towerGreen  "$SET_21="               // set Tower Green
#define releaseLDX  "$SET_30=0\r\n"          // Release Loader X-Motor
#define releaseLDY  "$SET_31=0\r\n"          // Release Loader Y-Motor
#define motparaLDX  "$SET_30=1\r\n"          // set Loader X-Motor param
#define motparaLDY  "$SET_31=1\r\n"          // set Loader Y-Motor param
#define rSET        "$SET_"                  // Rückmeldung eines $SET_ CMDs
#define rlogerror   "!E_"                    // Rückmeldung für Error Log
#define rlogwarn    "!W_"                    // Rückmeldung für Warn Log
#define rloginfo    "!I_"                    // Rückmeldung für Info Log
#define rlogdebug   "!D_"                    // Rückmeldung für Debug Log
#define rlogfifo    "!F_"                    // Rückmeldung für Fifo Log
#define rSMIF       "$SMIF_"                 // Rückmeldung SMIF Cmd
#define READ        "$READ_"
#define WRITE       "$WRITE_"
#define RES_LDY     "$INIT_0\r\n"        // Reset Loader Y
#define RES_LDX     "$INIT_1\r\n"        // Reset Loader X
#define RES_L1H     "$INIT_2\r\n"        // Reset Lift1 Height
#define RES_L2H     "$INIT_3\r\n"        // Reset Lift2 Height
#define RES_WCH     "$INIT_4\r\n"        // Reset WC Height
#define RES_WCP     "$INIT_5\r\n"        // Reset WC Phi
#define RES_PAT     "$INIT_6\r\n"        // Reset PA Tilt (Wobbler)
#define RES_PAR     "$INIT_7\r\n"        // Reset PA RotPos (Wobbler)
#define RES_PAH     "$INIT_8\r\n"        // Reset PA Height
#define RES_PAP     "$INIT_9\r\n"        // Reset PA Phi
#define RES_L1T     "$INIT_10\r\n"       // Reset Lift1 Tilt
#define RES_L2T     "$INIT_11\r\n"       // Reset Lift2 Tilt
#define RESBRD2     "$INIT_12\r\n"       // Reset Board2
#define RESBRD3     "$INIT_13\r\n"       // Reset Board3
#define RESBRD4     "$INIT_14\r\n"       // Reset Board4
#define RESBRD5     "$INIT_15\r\n"       // Reset Board5
#define RESBRD6     "$INIT_16\r\n"       // Reset Board6
#define RESBRD7     "$INIT_17\r\n"       // Reset Board7
#define RESBRD8     "$INIT_18\r\n"       // Reset Board8
#define RESBRD15    "$INIT_19\r\n"       // Reset Board15
#define vacoffLD    "$SETVAC_01=0\r\n"       // switch Vakuum Loader OFF
#define vaconLD     "$SETVAC_01=1\r\n"       // switch Vakuum Loader ON
#define vacoffPA    "$SETVAC_02=0\r\n"       // switch Vakuum Aligner OFF
#define vaconPA     "$SETVAC_02=1\r\n"       // switch Vakuum Aligner ON
#define vacoffWC1   "$SETVAC_03=0\r\n"      // switch Vakuum WC1 OFF
#define vaconWC1    "$SETVAC_03=1\r\n"      // switch Vakuum WC1 ON
#define vacoffWC2   "$SETVAC_04=0\r\n"      // switch Vakuum WC2 OFF
#define vaconWC2    "$SETVAC_04=1\r\n"      // switch Vakuum WC2 ON
#define vacoffCH4   "$SETVAC_05=0\r\n"      // switch Vakuum Chuck4 OFF
#define vaconCH4    "$SETVAC_05=1\r\n"      // switch Vakuum Chuck4 ON
#define vacoffCH6   "$SETVAC_06=0\r\n"      // switch Vakuum Chuck6 OFF
#define vaconCH6    "$SETVAC_06=1\r\n"      // switch Vakuum Chuck6 ON
#define vacoffCH8   "$SETVAC_07=0\r\n"      // switch Vakuum Chuck8 OFF
#define vaconCH8    "$SETVAC_07=1\r\n"      // switch Vakuum Chuck8 ON
#define vacalloff   "$SETVAC_09=0\r\n"      // switch alle Vakuumventile ausschalten
#define rSETVAC     "$SETVAC_"               // Antwortkennung SetVac
#define INIT_        "$INIT_"                  // Antworterkennung Reset
#define EE_Lift1    "$READ_1\r\n"            // EEPROM Lift1 Daten
#define EE_Lift2    "$READ_2\r\n"            // EEPROM Lift2 Daten
#define EE_Loader   "$READ_3\r\n"            // EEPROM Loader Daten
#define EE_Aligner  "$READ_4\r\n"            // EEPROM Prealigner Daten
#define EE_WC       "$READ_5\r\n"            // EEPROM Waferchanger Daten
#define EE_VAC      "$READ_6\r\n"            // EEPROM VAC Daten
#define EE_LOCK1    "$READ_23\r\n"           // EEPROM LOCK1 Daten
#define EE_LOCK2    "$READ_24\r\n"           // EEPROM LOCK2 Daten
#define boards      "$READ_30\r\n"
#define L1SensIN    "$READ_54\r\n"            // liest Lift1 Sensorwert
#define L2SensIN    "$READ_55\r\n"            // liest Lift2 Sensorwert
#define WSSensor    "$READ_56\r\n"            // liest Wafer Sensorwert
#define TempB2      "$READ_57\r\n"            // liest Temperatur Board 2
#define TempB3      "$READ_58\r\n"            // liest Temperatur Board 3
#define TempB4      "$READ_59\r\n"            // liest Temperatur Board 4
#define TempB5      "$READ_60\r\n"            // liest Temperatur Board 5
#define TempB6      "$READ_61\r\n"            // liest Temperatur Board 6
#define MainAVac    "$READ_62\r\n"            // liest Main AnalogVakuumwert
#define LDAVac      "$READ_63\r\n"            // liest LD AnalogVakuumwert
#define PAAVac      "$READ_64\r\n"            // liest PA AnalogVakuumwert
#define WC1AVac     "$READ_65\r\n"            // liest WC1 AnalogVakuumwert
#define WC2AVac     "$READ_66\r\n"            // liest WC2 AnalogVakuumwert
#define CH4AVac     "$READ_67\r\n"            // liest CH4 AnalogVakuumwert
#define $GETERR     "$READ_100\r\n"         // Service Fehlerliste auslesen
#define XRAC        "$X_"                   // direkt CMDs an RAC (ID,CMD in hex \r\n)
#define X2RAC       "&X"                    // direkt CMDs nur Daten Response
#define rXRAC       "&"                     // Antwortkennung Response XRAC $X1_ CMDs
#define rX2         "§"                     // Erkennungszeichen für Response der $X2_ CMDs
#define rRead       "$READ_"                // Antworterkennung Read EEPROM Daten
#define rBoards     "$R30_"                 // Antworterkennung
#define r_err       "$ERR_"                 // Errormeldungen nur loglevel.warnlog
#define rGET        "$GET_"
#define sz_arrPA    500                     // Arraysize für PA Ergebnisswerte
// -------- Stage CMDs ---------
#define mtcalib     "cal\r\n"
#define mtrm        "rm\r\n"
#define mtgetpos    "pos\r\n"
#define mtstatus    "st\r\n"
// -------- Mic CMDs -----------
#define EOT         4
#define ENQ         5
#define ACK         6
// -------- API CMDs -----------
#define BoxReset    "@RESET\r\n"            // löst Box Reset aus
#define API_VER     "@VER\r\n"              // INSBox Firmwareabfrage inkl. Boarddaten
#define API_IN      "@IN\r\n"               // API Sensorabfrage
#define API_STAT    "@STAT\r\n"             // API CMD STATUS
#define API_INIT    "@INIT_"             // API CMD INITSYSTEM
#define API_SETOUT  "@SETOUT_"              // API CMD Ausgänge schreiben
#define API_GETOUT  "@GETOUT\r\n"           // API CMD Ausgänge lesen
#define API_SETCAR  "@SETCAR_CT="           // API CMD SETCAR
#define API_GET_L   "@GET_S="               // API CMD GET -> Station
#define API_GET_SL  ",SL="                  // API CMD GET -> Slot
#define API_GETERR  "@GETERR\r\n"           // API CMD GETERR
#define API_ALIGN   "@ALIGN_A="             // API CMD ALIGN
#define API_ALROT   "@SETALROT_A="          // API CMD Prefix ALROT
#define API_GETALROT "@GETALROT\r\n"        // API CMD GETALROT
#define API_PREWC   "@PREWC_DIR="           // API CMD Prefix PREWC
#define API_WC      "@WC\r\n"               // API CMD WC
#define API_PUT_L   "@PUT_S="               // API CMD PUT -> Lift
#define API_PUT_SL  ",SL="                  // API CMD PUT -> Slot
#define API_UNLOAD  "@UNLOAD_L="            // API CMD UNLOAD
#define API_LOAD    "@LOAD_L="              // API CMD LOAD
#define API_WOSTART "@STARTMACRO_S="        // API CMD MACRO START
#define API_WOUPDATE "@UPDATEMACRO_S="      // API CMD MACRO UPDATE
#define API_WOGET "@GETWOBBLER\r\n"         // API CMD MACRO GETWOBBLER
#define API_WOSTOP "@STOPMACRO"             // API CMD MACRO STOP
#define API_WOBLMP "@SETWOBLAMP_I="         // API CMD WOBBLER Lampe
#define API_SENSOR  "@SENSOR_0\r\n"         // API CMD SENSOR
#define API_MAP_L   "@MAP_L="
#define API_GETMAP  "@GETMAP_L="
#define API_GETFNRES "@GETFNRES\r\n"        // API CMD GETFNRES
#define p1GETWAFER  "@GW_L="
#define p2GETWAFER  " CT="
#define p3GETWAFER  " SL="
#define p4GETWAFER  " ID="
#define p5GETWAFER  " FN="
#define p6GETWAFER  " AN="
#define API_Stage   "@STAGE_OK=1\r\n"
#define API_ENDJOB  "@ENDJOB_0\r\n"
#define API_SERVICE1 "@SERVICE_M=1\r\n"
#define API_SERVICE0 "@SERVICE_M=0\r\n"
#define API_TWIdelay "@SERVICE_M="
#define API_GETSTATE "@SVCGS_0\r\n"
// ------ API Antwortstring-Prefix ----
#define rAPIin      "@IN_"
#define rAPIver     "@VER_FW="
#define rAPIinit    "@INIT_RET=0"           // BOX Antworterkennung
#define rAPIout     "@SETOUT_"
#define rAPIgetout  "@GETOUT_"

//#define rAPIsensor  "@SENSOR_"              // BOX Antworterkennung
#define rAPIstat    "@STAT_"                // BOX Antworterkennung
#define rAPIMap     "@GETMAP_L="            // BOX Antworterkennung
#define rStageWafer "@GW_STAGE="            // BOX Antworterkennung für Wafer auf Stage
#define rUNLOAD     "@UNLOAD_L="            // BOX Antworterkennung für UNLOAD
#define rAPIerr     "@GETERR_"
#define rAPIAlign   "@ALIGN_RET="           // BOX Antwortkennung für CMD ALIGN

#define errmess1    "Please check your input! Only numbers are allowed."
#define errmess2    "File could not renamed."
#define errmess3    "Something went wrong. Please check data!"
#define errmess4    "please select Lift1 or Lift2"
#define errmess5    "please select minimum one slot"
#define errmess6    "please select Lift"

#define actpos      "test"
#define addlifthgt    2

#define POS_ABS           1  // Setzt den Wert einer Einheit absolut
#define POS_CONST         2  // Fuehrt eine Einheit mit konst. Spannung
#define READ_POS          3  // Liest den Status der Einheit  READ_STATUS
#define SET_VALUE         4  // Schaltet ein Modul aktiv/inaktiv
#define GET_VALUE         5  // Liest den Modulstatus
#define SET_PARAMETER     6  // Setzen der Betriebsart von einer Einheit
#define GET_PARAMETER     7  // Lesen der Betriebsart
#define READ_INFO         8  // Liest Geraetestatus
#define RESET_UNIT        9  // Loest Reset einer Einheit aus
#define FN_BREAK         10  // Abbruch einer Bewegung
#define WAIT_CHANGE      11  // Wartet auf Änderung
#define LOAD_MODE        12  // Gehe in den Download - Zustand
#define DOWN_LOAD        13  // Download ins Flash
#define UP_LOAD          14  // Upload vom Flash
#define READ_MEM         15  // Lesen von Speicherinhalten
#define CLEAR_MSGS       16  // Löscht ausstehende Messages
#define CALIBRATE        17  // Kalibriert Einheit
#define LIFT_INVENTORY   18  // Löst einen Inventory bei LIFT aus
#define LIFT_POS         19  // Positioniert einen LIFT

#define POSA_OK          32  // Einheit ist mit "POS_ABS" fertig
#define POSC_OK          33  // Einheit ist mit "POS_CONST" fertig
#define POS_STAT         34  // Status der "READ_POS" Funktion   -> 9 Data
#define SET_VALUE_OK     35  // Wert wurde übernommen
#define GET_VALUE_OK     36  // Wert wurde gelesen
#define SET_PARAM_OK     37  // Parameter wurde übernommen
#define GET_PARAM_OK     38  // Parameter wurde gelesen
#define RESET_OK         39  // Reset durchgefhrt
#define INFO_STAT        40  // Geraetestatus
#define BREAK_OK         41  // Laufende Funktion wurde abgebrochen
#define MEM_STAT         45  // Speicher-Inhalt
#define CALIBRATE_OK     48  // Kalibrierung fertig
#define LIFT_INV_OK      49  // Liftinventory fertig
#define LIFT_POS_OK      50  // Liftpositionierung fertig
#define FN_BUSY          64  // Funktion wird noch bearbeitet
#define FN_CANCEL        65  // Funktion wurde abgebrochen
#define FN_BLOCKED       66  // Funktion kann nicht ausgelöst werden
#define FN_TIMEOUT       67  // Timeout, Zeit für korrekte Ausfhrung
#define FN_NOT_PRESENT   68  // Funktion ist hardwaremäßig nicht vorhanden
#define ERR_MSG          69  // Fehler in der Nachricht, Falsche L„nge
#define ERR_ID           70  // Falsche Einheit wurde angesprochen
#define ERR_POS          71  // Falsche Stellung oder Position
#define ERR_VAL          72  // übergebene Werte falsch
#define ERR_SENS         73  // Einheit fehlerhaft, Sensor defekt u.a.
#define ERR_END          74  // Mechanisches Ende berührt
#define ERR_COMM         75  // Protokoll-Fehler in der Interprozessor-Kom
#define ERR_NODE         76  // Node ungültig
#define ERR_EMERGENCY    77  // Emergency Stop
#define ERR_CALIB        78  // Kalibrierung nicht möglich
#define ERR_POS_DIFF     79  // Positionsdifferenzgrenze überschritten
#define ERR_MOTVOLTAGE   80  // Motorspannung ausgefallen
#define UNKNOWN_CMD     150  // Unbekannter Befehl

#define NODE_NOT_CONNECTED	81	 //
#define MSPF_NO_MEMORY		82	 //
#define RSPF_NO_MEMORY		83	 //
#define PIF_NO_MEMORY		84	 //
#define POF_NO_MEMORY		85	 //
#define ERRORLIST_FULL		86	 //
#define UNIT_NOT_PRESENT	87	 //
#define CLEAN_TIMEOUT		88
#define VACUUM_LOW			114

#define BOARD				0
#define MOTOR1				1	// Lift2-Heigth(2);Lift1-Height(3);PARotPos(4);Loader-X(5);Stage-X(6)
#define MOTOR2				2	// Lift2-Tilt(2);Lift1-Tilt(3);PA-Phi(4);Loader-Y(5);Stage-Y(6)
#define MOTOR3				3	// PA-Heigth(3);PA-Tilt(4);WC-Heigth(5);WC-PHI(6)
#define TEMPERATURE			4	// MB:T(C) = 0.4 * Value(Counts)
#define VOLTAGE1			5	// MB:UB Motor 1/SB:8V Spannung 0.0392*Value(Counts)
#define VOLTAGE2			6	// MB:UB Motor 2/SB:12V Spannung 0.0392*Value(Counts)
#define VOLTAGE3			7	// MB:UB Motor 3/SB:-12V Spannung 0.0392*Value(Counts)
#define VOLTAGE4			8	// MB:UB Motor 4/SB:24V Spannung 0.0392*Value(Counts)
#define INPORT1				9
#define INPORT2				10	// MB:Eingangsbuffer 2
#define OUTPORT				11
#define INBIT1				12	//MB: /SB:
#define INBIT2				13	//MB: /SB:
#define INBIT3				14	//MB: /SB:
#define INBIT4				15	//MB: /SB:
#define INBIT5				16	//MB:
#define INBIT6				17  //MB:
#define INBIT7				18  //MB:
#define INBIT8				19  //MB:
#define INBIT9				20  //MB:
#define INBIT10				21  //MB:
#define INBIT11				22  //MB:
#define INBIT12				23  //MB:
#define INBIT13				24  //MB:
#define INBIT14				25  //MB:
#define OUTBIT1				26	//MB: /SB:
#define OUTBIT2				27	//MB: /SB:
#define OUTBIT3				28	//MB: /SB:
#define OUTBIT4				29	//MB: /SB:
#define OUTBIT5				30	//MB: /SB:
#define OUTBIT6				31	//MB: /SB:
#define OUTBIT7				32	//MB: /SB:
#define OUTBIT8				33	//MB: /SB:
#define SWITCH1				34	//SB:
#define SWITCH2				35	//SB:
#define SWITCH3				36	//SB:
#define SWITCH4				37	//SB:
#define SWITCH5				38	//SB:
#define SWITCH6				39	//SB:
#define SWITCH7				40	//SB:
#define SWITCH8				41	//SB:
#define TOWERLP1			42	//SB:
#define TOWERLP2			43	//SB:
#define TOWERLP3			44	//SB:
#define TOWERHN1			45	//SB:
#define SWITCH13			46	//SB:
#define SWITCH14			47	//SB:
#define SWITCH15			48	//SB:
#define SWITCH16			49	//SB:
#define PWM_OUTPUT1			50	//SB:
#define PWM_OUTPUT2			51	//SB:
#define PWM_OUTPUT3			52	//SB:
#define ANALOG_INPUT1		53	//SB: ANALOGINPUT1, 7 LD, 8 CH4
#define ANALOG_INPUT2		54	//SB: ANALOGINPUT2, 7 WC1
#define ANALOG_INPUT3		55	//SB: ANALOGINPUT3, 7 WC2
#define ANALOG_INPUT4		56	//SB: ANALOGINPUT4, 7 PA
#define MAINVACUUM			57	//SB: ANALOGINPUT5, 8
#define ANALOG_INPUT6		58	//SB:
#define ANALOG_INPUT7		59	//SB:
#define VACUUMSWITCH1		60	//SB: Loader (N7)		Chuck4 (N8)
#define VACUUMSWITCH2		61	//SB: WC left (N7)
#define VACUUMSWITCH3		62	//SB: WC right (N7)	Chuck8 (N8)
#define VACUUMSWITCH4		63	//SB: Prea (N7)
#define VACUUMSWITCH5		64	//SB:
#define VACUUMSWITCH6		65	//SB:
#define VACUUMSWITCH7		66	//SB:
#define VACUUMUNIT1			67	//SB: CHUCK4
#define VACUUMUNIT2			68	//SB:
#define VACUUMUNIT3			69	//SB:
#define VACUUMUNIT4			70	//SB:
#define VACUUMUNIT5			71	//SB:
#define VACUUMUNIT6			72	//SB:
#define VACUUMUNIT7			73	//SB:
#define LIFT_LOCK1			74	//SB:
#define LIFT_LOCK2			75	//SB:
#define SENSOR_VALUE1		76	//SB:
#define SENSOR_VALUE2		77	//SB:
#define SENSOR_VALUE3		78	//SB:
#define SENSOR_VALUE4		79	//SB:
#define AMPL_SENSOR1			80	//SB:
#define AMPL_SENSOR2			81	//SB:
#define AMPL_SENSOR3			82	//SB:
#define AMPL_SENSOR4			83	//SB:
#define EXISTENCESENSOR1		84	//SB:  /PAB:AMPL_SENSOR1 Verstärkung
#define EXISTENCESENSOR2		85	//SB:
#define EXISTENCESENSOR3		86	//SB:
#define EXISTENCESENSOR4		87	//SB:
#define VACUUMGROUP			88	//SB:
#define EMERGENCYSTOP		89	//SB:
#define BOARD_REVISION		90	//MB: /SB:  /PAB:
#define MEASUNIT			92	//PAB:
#define MEASTRANSMITTER		93	//PAB:
#define CHANGE_STATUS		199
#define POWER_FAIL			200
#define MOT_POWER_FAIL		201
#define DCDC_POWER_OK   	202
#define LIFT				210
#define TASK_0				250
#define TASK_1				251
#define TASK_2				252

#define PAsetPhi                1       // Verwendung in rXcmd
#define MeasAnalog              2       // Verwendung in rXcmd
#define MeasAmplif              3       // Verwendung in rXcmd
#define MeasON                  4       // Verwendung in rXcmd
#define getLift1                5
#define getLift2                6
#define setLift1                7
#define setLift2                8
#define getLoader_X             9
#define getLoader_Y            19
#define setLoader_X            10
#define setLoader_Y            20
#define getPrea                11
#define setPrea                12
#define getWC                  13
#define setWC                  14
#define getTilt1               15
#define getTilt2               16
#define setTilt1               17
#define setTilt2               18
#define getPreaPhi             21
#define getWCPhi               22
#define getTilt                23
#define getRotPos              24
#define readmotstat            25
#define getDC8                 26
#define getDC12                26
#define getDCM12               28
#define getDC24                29
#define getCONSTPOS            30
#define getVacParamLD          40
#define getVacParamPA          41
#define setVacParam            42
#define getLock1Param          43
#define getLock2Param          44
#define amount                 100
#define logistic               "1"      // 1=SMIF Slot ohne Wafer wird nicht angefahren

// ----------- MIC ---------------
#define mic_secs    "01010101010101010101"

// -------------------------------
/* SMIF errorcodes */
#define ISE_INIT    "$SMIF_1="
#define ISE_HOME    "$SMIF_2="
#define ISE_BEGIN   "$SMIF_3="
#define ISE_END     "$SMIF_4="
#define ISE_WGET    "$SMIF_5="
#define ISE_WPUTZ   "$SMIF_6="
#define ISE_ZDOWN   "$SMIF_7="
#define ISE_ZUP     "$SMIF_8="
#define ISE_RETRACT "$SMIF_9="
#define ISE_INV     "$SMIF_10="
#define ISE_STATUS  "$SMIF_11="
#define ISE_ASYNC   "$SMIF_12="
#define ISE_GCONF2  "$SMIF_13="
#define ISE_GCONF3  "$SMIF_14="
#define ISE_GCONF4  "$SMIF_15="
#define ISE_GCONF5  "$SMIF_16="
#define ISE_GCONF6  "$SMIF_17="
#define ISE_PCONF2  "$SMIF_18="
#define ISE_PCONF3  "$SMIF_19="
#define ISE_PCONF4  "$SMIF_20="
#define ISE_PCONF5  "$SMIF_21="
#define ISE_PCONF6  "$SMIF_22="
#define ISE_ID      "$SMIF_23="

#define rISE_INIT       1
#define rISE_HOME       2
#define rISE_BEGIN      3
#define rISE_END        4
#define rISE_WGET       5
#define rISE_WPUTZ      6
#define rISE_ZDOWN      7
#define rISE_ZUP        8
#define rISE_RETRACT	9
#define rISE_INV		10
#define rISE_STATUS     11
#define rISE_ASYNC      12
#define rISE_GCONF2     13
#define rISE_GCONF3     14
#define rISE_GCONF4     15
#define rISE_GCONF5     16
#define rISE_GCONF6     17
#define rISE_PCONF2     18
#define rISE_PCONF3     19
#define rISE_PCONF4     20
#define rISE_PCONF5     21
#define rISE_PCONF6     22
#define rISE_ID         23
#define rISE_OK         1
const char* const IseErrCode[180] =
{
    "cmd ok",
    "motor in end position",
    "motor in error position",
    "unkown",
    "unkown",
    "motor stalled",
    "timeout",
    "illegal start range",
    "target range not reached",
    "key depressed",
    "cmd not complete",
    "hardware halt",
    "no motor voltage",
    "no motor current",
    "encoder error",
    "timeout too big",
    "no initialization",
    "range not reached",
    "unknown command",
    "motor stopped",
    "step error",
    "init error RS232",
    "memory fault",
    "driver mismatch error",
    "illegal frequency parameter",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "internal error 1",
    "internal error 2",
    "internal error 3",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "type error",
    "unkown",
    "unkown",
    "unkown",
    "illegal frequency parameter",
    "illegal position parameter",
    "illegal direction parameter",
    "illegal parameter",
    "timeout",
    "forever busy",
    "error dual port ram",
    "motor in error position",
    "motor in error position",
    "motor in end position",
    "motor in end position",
    "step error",
    "motor already in target range",
    "motor not in target range",
    "motor not in error position",
    "no error range identified",
    "can not exit error range",
    "previous error not yet eliminated",
    "key not depressed",
    "internal error",
    "no motor voltage",
    "no motor current",
    "unkown",
    "unkown",
    "unkown",
    "no initialization",
    "hhx bit(s) active",
    "optical flag sensor index error",
    "command cannot be executed",
    "air cylinder error",
    "internal error",
    "level cmd cannot be executed",
    "out of level range",
    "unkown",
    "unkown",
    "blocked state",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "timeout",
    "illegal command",
    "error in the number of parameters",
    "parameter value error",
    "command syntax error",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "service command not enabled",
    "unkown",
    "unkown",
    "command cannot be executed",
    "unkown",
    "unkown",
    "unkown",
    "command execution aborted",
    "pod not placed",
    "pod motor sensor error",
    "potential wafer crash situation",
    "cannot discover cassette",
    "no initialization",
    "position out of range",
    "unkown",
    "error check config data 2",
    "error check config data 3",
    "error check config data 4",
    "configuration error 1",
    "configuration error 2",
    "configuration error 3",
    "configuration error 4",
    "crash sensor error",
    "cannot open pod",
    "cannot close pod",
    "pod not in home position",
    "error check config data 5",
    "flyswat timeout",
    "safety shutdown",
    "unkown",
    "unkown",
    "error check config data 6",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "pod not open",
    "pod not closed",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "unkown",
    "invalid scan conditions",
    "slot not empty",
    "slot empty",
    "invalid scan case 1",
    "invalid scan case 2",
    "invalid scan case 3",
    "invalid scan case 4",
    "invalid scan case 5"
};
const char* const ISE_cmd[30] =
{
    "OK",
    "INIT",
    "HOME",
    "BEGIN",
    "END",
    "WGET",
    "WPUTZ",
    "ZDOWN",
    "ZUP",
    "RETRACT",
    "INV",
    "STATUS",
    "ASYNC",
    "GCONF2",
    "GCONF3",
    "GCONF4",
    "GCONF4",
    "GCONF5",
    "GCONF6",
    "PCONF2",
    "PCONF3",
    "PCONF4",
    "PCONF5",
    "PCONF6",
    "ID",
    "ERROR",
    "SLOT",
    "COUNT",
    "LASER"
};
const char* const GET_cmd[100] =
{
    "Get ?",                    // 0
    "Get @VER",
    "Get @STAT",
    "Get @IN",
    "Get @GETOUT",
    "Get @GETALROT",
    "Get @GETERR",
    "Get @SETCAR",
    "Get @INIT",
    "Get @SETOUT",
    "Get @MAP",                    // 10
    "Get @GET",
    "Get @PUT",
    "Get @ALIGN",
    "Get @SETALROT",
    "Get @PREWC",
    "Get @WC",
    "Get @GETMAP",
    "Get @L1MAP",
    "Get @L2MAP",
    "Get @GETFNRES",              // 20
    "Get ?",
    "get ISE-ZSTROKE",
    "get ISE-DELAY(*20)",
    "get PA-Reader displ(*10)",
    "get WO-Flag Joystick",
    "get ",
    "get ",
    "get ISE-LOGISTIC",
    "get PA-PHI maxdev_fric",
    "get ",                     // 30
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get list vac_valve state", // 40
    "get list material_manager",
    "get list found_wafer",
    "get list reset state",
    "get list api cmd",
    "get list feeder state",
    "get list api state",
    "get state powerfail",
    "get state ACR",
    "get ",
    "get state PIN C",
    "get state DDR C",
    "get state PORT C",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get ",
    "get "
};
const char* const SET_cmd[100] =
{
    "set flag write EPROM",
    "set reset INSBox",
    "set break motor move",
    "set EEMOTDATOK",
    "set mode simulation",
    "set mode service",
    "set log level debug",
    "set log level warn",
    "set log level error",
    "set finger to slot number lift 1",
    "set finger to slot number lift 2",
    "set wafer to slot number lift 1",
    "set wafer to slot number lift 2",
    "set wafer change",
    "set simulation counter",
    "set flag mainvac (debug)",
    "set check vacuum valve",
    "set ISE log",
    "set ISE cmd delay",
    "set tower horn",
    "set tower lamp 1",
    "set tower lamp 2",
    "set tower lamp 3",
    "set tmp PA displacement",
    "set ISE z stroke -> EPROM",
    "set ISE polling",
    "set option friction ",
    "set ISE flag logistic",
    "set PA max deviation friction",
    "set release loder x",
    "set release loder y",
    "set ",
    "set ",
    "set ",
    "set calibration lift sensor",
    "set ",
    "set ",
    "set  get map lift",
    "set map lift",
    "set unload carrier",
    "set load carrier",
    "set parm from board lift 1",
    "set parm from board lift 2",
    "set parm to board lift 1",
    "set parm to board lift 2",
    "set ",
    "set ",
    "set lock lift 1",
    "set lock lift 2",
    "set lift 1 height",
    "set lift 1 tilt",
    "set lift 2 height",
    "set lift 2 tilt",
    "set loader x",
    "set loader y",
    "set PA tilt",
    "set PA rotpos",
    "set PA height",
    "set PA phi",
    "set PA pos middle",
    "set WC height",
    "set WC phi",
    "set ",
    "set ",
    "set wobbler lamp",
    "set ",
    "set ",
    "set ",
    "reset error level",
    "reset list material manager",
    "reset list found wafer",
    "set list material manager",
    "set list found wafer",
    "set ",
    "set pos const lift 1 height",
    "set pos const lift 1 tilt",
    "set pos const lift 2 height",
    "set pos const lift 2 tilt",
    "set pos const loader x",
    "set pos const loader y",
    "set pos const PA tilt",
    "set pos const PA rotpos",
    "set pos const PA height",
    "set pos const PA phi",
    "set pos const WC height",
    "set pos const WC phi",
    "set ",
    "set ",
    "set ",
    "set sync node",
    "set ",
    "set ",
    "set ",
    "set ",
    "set ",
    "set ",
    "set simple log",
    "set log level fifo",
    "set flag INIT",
    "set "
};
const char* const READ_cmd[100] =
{
    "read EPROM lift1",
    "read EPROM lift2",
    "read EPROM loader",
    "read EPROM prealigner",
    "read EPROM wafer changer",
    "read EPROM vacuum",
    "read EPROM cassette 1",
    "read EPROM cassette 2",
    "read EPROM cassette 3",
    "read EPROM cassette 4",
    "read EPROM cassette 5",
    "read EPROM cassette 6",
    "read EPROM cassette 7",
    "read EPROM cassette 8",
    "read EPROM cassette 9",
    "read EPROM cassette 10",
    "read EPROM cassette 11",
    "read EPROM cassette 12",
    "read EPROM cassette 13",
    "read EPROM cassette 14",
    "read EPROM cassette 15",
    "read EPROM cassette 16",
    "read EPROM lock 1",
    "read EPROM lock 2",
    "read EPROM tower",
    "read EPROM joystick ADC",
    "read ",
    "read ",
    "read ",
    "read boards",
    "read ",
    "read ",
    "read pos lift 1 height",
    "read pos lift 2 height",
    "read pos loader x",
    "read pos loader y",
    "read pos prealigner height",
    "read pos prealigner phi",
    "read pos prealigner rotpos",
    "read pos prealigner tilt",
    "read pos wafer changer height",
    "read pos wafer changer phi",
    "read ",
    "read ",
    "read ",
    "read ",
    "read ",
    "read ",
    "read ",
    "read voltage 8 VDC",
    "read voltage 12 VDC",
    "read voltage -12 VDC",
    "read voltage 24 VDC",
    "read carsize lift 1",
    "read carsize lift 2",
    "read sensor wafer size",
    "read Node 2 -> temperature",
    "read Node 3 -> temperature",
    "read Node 4 -> temperature",
    "read Node 5 -> temperature",
    "read Node 6 -> temperature",
    "read vac_analog main",
    "read vac_analog loader",
    "read vac_analog aligner",
    "read vac_analog WC 1",
    "read vac_analog WC 2",
    "read vac_analog chuck 4 inch",
    "read flag EPROM2",
    "read flag error stop",
    "read state feeder",
    "read state diag leds",
    "read ",
    "read ",
    "read ",
    "read state power fail",
    "read volt Node2_Lift2-Heigth",
    "read volt Node3_Lift1-Heigth",
    "read volt Node4_PARotPos",
    "read volt Node5_Loader X",
    "read ",
    "read volt Node2_Lift2-Tilt",
    "read volt Node3_Lift1-Tilt",
    "read volt Node4_PA Phi",
    "read volt Node5_Loader Y",
    "read ",
    "read ",
    "read volt Node3_PA Height",
    "read volt Node4_PA WobTilt",
    "read volt Node5_WC Height",
    "read volt Node6_WC Phi",
    "read ",
    "read ",
    "read ",
    "read ",
    "read ",
    "read ",
    "read state error stop level",
    "read ",
    "read state system",
    "read api error"
};
const char* const SETVAC_cmd[10] =
{
    "SETVAC loader",
    "SETVAC PA",
    "SETVAC WC 1",
    "SETVAC WC 2",
    "SETVAC Chuck 4 inch",
    "SETVAC Chuck 6 inch",
    "SETVAC Chuck 8 inch",
    "SETVAC ?",
    "SETVAC all off"
};
const char* const EC_racmess[30] =
{
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14"
};
const char* const EC_racpoll[20] =
{
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9"
};
const char* const EC_sendfrm[20] =
{
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",    // Checksumme
    "8",
    "9"
};
const char* const EC_feedercycle[130] =
{
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31",
    "32",
    "33",
    "34",
    "35",
    "36",
    "37",
    "38",
    "39",
    "40",
    "41",
    "42",
    "43",
    "44",
    "45",
    "46",
    "47",
    "48",
    "49",
    "50",
    "51",
    "52",
    "53",
    "54",
    "55",
    "56",
    "57",
    "58",
    "MAINVAC",
    "60",
    "61",
    "62",
    "63",
    "64",
    "65",
    "66",
    "67",
    "68",
    "69",
    "70",
    "71",
    "72",
    "73",
    "74",
    "75",
    "76",
    "77",
    "78",
    "79",
    "80",
    "81",
    "82",
    "83",
    "84",
    "85",
    "86",
    "87",
    "88",
    "89",
    "90",
    "91",
    "92",
    "93",
    "94",
    "95",
    "96",
    "97",
    "98",
    "99",
    "100",
    "101",
    "102",
    "103",
    "104",
    "105",
    "106",
    "107",
    "108",
    "109",
    "110",
    "111",
    "112"
};
const char* const EC_feeder[146] =
{
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31",
    "32",
    "33",
    "34",
    "35",
    "36",
    "37",
    "38",
    "39",
    "40",
    "41",
    "42",
    "43",
    "44",
    "45",
    "46",
    "47",
    "48",
    "49",
    "50",
    "51",
    "52",
    "53",
    "54",
    "55",
    "56",
    "57",
    "58",
    "59",
    "60",
    "61",
    "62",
    "63",
    "64",
    "65",
    "66",
    "67",
    "68",
    "69",
    "70",
    "71",
    "72",
    "73",
    "74",
    "75",
    "76",
    "77",
    "78",
    "79",
    "80",
    "81",
    "82",
    "83",
    "84",
    "85",
    "86",
    "87",
    "88",
    "89",
    "90",
    "91",
    "92",
    "93",
    "94",
    "95",
    "96",
    "97",
    "98",
    "99",
    "100",
    "101",
    "102",
    "103",
    "104",
    "105",
    "106",
    "107",
    "108",
    "109",
    "110",
    "111",
    "112",
    "113",
    "114",
    "115",
    "116",
    "117",
    "118",
    "119",
    "120",
    "121",
    "122",
    "123",
    "124",
    "125",
    "126",
    "127",
    "128",
    "129",
    "130",
    "131",
    "132",
    "133",
    "134",
    "135",
    "136",
    "137",
    "138",
    "139",
    "140",
    "141",
    "142",
    "143",
    "144",
    "145"
};
const char* const EC_main[151] =
{
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31",
    "32",
    "33",
    "34",
    "35",
    "36",
    "37",
    "38",
    "39",
    "40",
    "41",
    "42",
    "43",
    "44",
    "45",
    "46",
    "47",
    "48",
    "49",
    "50",
    "51",
    "52",
    "53",
    "54",
    "55",
    "56",
    "57",
    "58",
    "59",
    "60",
    "61",
    "62",
    "63",
    "64",
    "65",
    "66",
    "67",
    "68",
    "69",
    "70",
    "71",
    "72",
    "73",
    "74",
    "75",
    "76",
    "77",
    "78",
    "79",
    "80",
    "81",
    "82",
    "83",
    "84",
    "85",
    "86",
    "87",
    "88",
    "89",
    "90",
    "91",
    "92",
    "93",
    "94",
    "95",
    "96",
    "97",
    "98",
    "99",
    "100",
    "101",
    "102",
    "103",
    "104",
    "105",
    "106",
    "107",
    "108",
    "109",
    "110",
    "111",
    "112",
    "113",
    "114",
    "115",
    "116",
    "117",
    "118",
    "119",
    "120",
    "121",
    "122",
    "123",
    "124",
    "125",
    "126",
    "127",
    "128",
    "129",
    "130",
    "131",
    "132",
    "133",
    "134",
    "135",
    "136",
    "137",
    "138",
    "139",
    "140",
    "141",
    "142",
    "143",
    "144",
    "145",
    "146",
    "147",
    "148",
    "149",
    "150"
};
const char* const RACErrCode[186] =
{
    "nn",
    "nn",
    "PROTOCOL_ERROR_1",
    "PROTOCOL_ERROR_2",
    "PROTOCOL_ERROR_3",
    "PROTOCOL_ERROR_4",
    "PROTOCOL_ERROR_5",
    "PROTOCOL_ERROR_6",
    "CHECKSUM_ERROR",
    "SEQUENCE_ERROR_1",
    "SEQUENCE_ERROR_2",
    "SEQUENCE_ERROR_3",
    "SEQUENCE_ERROR_4",
    "SEQUENCE_ERROR_5",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "INIT_ERROR_RES",
    "BOARDS_NOT_READY",
    "nn",
    "nn",
    "nn",
    "nn",
    "RSPF_MCNT_ERROR",
    "nn",
    "nn",
    "nn",
    "USART1_RX_ERROR",
    "USART1_FORMAT_ERROR",
    "MESSAGE_TO_LONG",
    "INTERRUPT_ERROR_0",
    "MSPF_MCNT_ERROR",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "NODE_NOT_CONNECTED",
    "MSPF_NO_MEMORY",
    "RSPF_NO_MEMORY",
    "DATA_NOT_VALID",
    "POF_NO_MEMORY",
    "ERRORLIST_FULL",
    "UNIT_NOT_PRESENT",
    "CLEAN_TIMEOUT",
    "MOVE_DISABLED",
    "CHECK_MOTDATA",
    "INIT_NOT_VALID",
    "LIFT_NOT_PRESENT",
    "STATION_NOT_VALID",
    "CARRIERTYPE_NOT_VALID",
    "SLOT_NOT_VALID",
    "MAP_NOT_VALID",
    "LOCK_NOT_VALID",
    "TILT_NOT_VALID",
    "WAFER_ON_ALIGNER",
    "NO_WAFER_ON_ALIGNER",
    "LOADER_VACUUM_ERR",
    "ALIGNER_VACUUM_ERR",
    "WC1_VACUUM_ERR",
    "WC2_VACUUM_ERR",
    "CHUCK_VACUUM_ERR",
    "nn",
    "nn",
    "nn",
    "CMD_BLOCKED",
    "TIMEOUT",
    "IS_BUSY",
    "OUTOFMEMORY",
    "VACUUM_ERR",
    "VACUUM_LOW",
    "NO_CARRIER",
    "WAFER_FOUND",
    "POS_NOT_DEFINED",
    "WAFERSIZE_NOT_DEFINED",
    "RETRY_SLOTNR_ERROR",
    "CHECK_LOADER_ARM",
    "CHECK_CHANGER_ARM",
    "CHUCK_ALIGNER_VACUUM_ON",
    "WAFER_CARSIZE_MISMATCH",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "NODE_IS_ZERO",
    "UNKNOWN_CONTROLFIELD",
    "COUNT_RR",
    "COUNTER_FULL",
    "NO_WAFER_ON_CHANGER",
    "SEQERR_NO_RESPONSE",
    "SEQERR_RINFO",
    "SEQERR_RR",
    "SEQERR_RNR",
    "feeder_needes_reset",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "SMIF1_RESP_ERROR",
    "SMIF2_RESP_ERROR",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "nn",
    "POWER_OFF_INIT_NOT_POSSIBLE",
    "PA_CAL_SENSOR_ERR"
};

// #define S1F0           "$ASYST_1=0\r"   // Abort Transaction
// #define S1F1           "$ASYST_1=1\r"   // Are you there request
// #define S1F2           "$ASYST_1=2\r"   // On line Data (D)
// #define S1F5           "$ASYST_1=5\r"   // Formatted Status request (FSR)
// #define S1F6           "$ASYST_1=6\r"   // Formatted Status data (FSD)
// #define S2F13          "$ASYST_2=13\r"  // Equip. Constant Request (ECR)
// #define S2F14          "$ASYST_2=14\r"  // Equip. Constant Data (ECD)
// #define S2F15          "$ASYST_2=15\r"  // New Equip. Constant Send (ECS)
// #define S2F16          "$ASYST_2=16\r"  // New Equip. Constant Acknowledge (ECA)
// #define S2F21          "$ASYST_2=21\r"  // Remote Constant Send (RCS)
// #define S2F22          "$ASYST_2=22\r"  // Remote Constant Acknowledge (RCA)
// #define S2F25          "$ASYST_2=25\r"  // Loopback Diag. Request (LDR)
// #define S2F26          "$ASYST_2=26\r"  // Loopback Diag. Data (LDD)

// #define S2F33          "$ASYST_2=33\r"  // DR	S2,F33 Define Report
// #define S2F34          "$ASYST_2=34\r"  // DRA	S2,F34 Define Report Acknowledge
// #define S2F35          "$ASYST_2=35\r"  // LER	S2,F35 Link Event Report
// #define S2F36          "$ASYST_2=36\r"  // LERA	S2,F36 Link Event Report Acknowledge
// #define S2F37          "$ASYST_2=37\r"  // EDER	S2,F37 Enable/Disable Event
// #define S2F38          "$ASYST_2=38\r"  // EERA	S2,F38 Enable/Disable Event Report Acknowledge
// #define S2F41          "$ASYST_2=41\r"  // HCS	S2,F41 Host Command Send
// #define S2F42          "$ASYST_2=42\r"  // HCA	S2,F42 Host Command Acknowledge

// #define S5F1           "$ASYST_5=1\r"   // ARS	S5,F1 Alarm Report Send
// #define S5F3           "$ASYST_5=3\r"   // EAN	S5,F3 Enable/Disable Alarm Send
// #define S5F4           "$ASYST_5=4\r"   // EAA	S5,F4 Enabie/Disable Alarm ACK
// #define S6F13          "$ASYST_6=13\r"  // AERS	S6,F13 Annotated Event Report Send
// #define S6F14          "$ASYST_6=14\r"  // AERA	S6,F14 Annotated Event Report Send Acknowledge
// #define S10F3          "$ASYST_10=3\r"  // VTN	S10,F3 Terminal Display Single
// #define S10F4          "$ASYST_10=4\r"  // VTA	S10,F4 Terminal Display Single Acknowledge
// ---- Stream ----
#define ASYST_STATUS    "$ASYST_1="     // FSR FC=0 Statusabfrage
#define ASYST_CMD       "$ASYST_2="     // HCS Host command
#define ASYST_SCONFIG   "$ASYST_3="     // ECS set data from config ID
#define ASYST_RCONFIG   "$ASYST_4="     // ECR read data from config ID
#define ASYST_EVENT     "$ASYST_5="     // EDER Enable/Disable Event
// ---- function ----
#define STATUS			"0"
#define cmdAUTO			"1"  // Switch Indexer to AUTO mode
#define cmdCALIB		"2"  // Calibrate elevator HOME position
#define cmdCASSETTE		"3"  // cassette present in stage operation
#define cmdCLEAR_SLOT	"4"  // Change slot status to "Unkown"
#define cmdESLOT		"5"  // Move elevator up/down to find next empty slot
#define cmdGOTO			"6"  // Go to specified (absolute) position
#define cmdHOME			"7"  // Return Indexer to Home
#define cmdLOCK			"8"  // Lock port
#define cmdMAN_GOTO		"9"  // Move elevator to the specified (absolute) position at specified speed and acceleration in MANUAL mode
#define cmdMAN_UNLK		"10"  // Unlock port in MANUAL mode
#define cmdMANUAL		"11"  // Switch Indexer to MANUAL mode
#define cmdMAP			"12"  // Run elevator to rescan cassette map
#define cmdMOVE			"13"  // Move Indexer up/down a specified distance
#define cmdRESET		"14"  // Clear alarm in Indexer
#define cmdSELF_TEST	"15"  // Perform self-test
#define cmdSLOT			"16"  // Go to the specified slot number
#define cmdSQUAT_MOVE	"17"  // Move Indexer up/down a specified distance and ignore vertical protrusion signal
#define cmdSTAGE		"18"  // Go to stage position
#define cmdSTOP			"19"  // Abort current operation
#define cmdTWEEKDN		"20"  // Move elevator down a fixed distance to send a reticle
#define cmdTWEEKUP		"21"  // Move elevator up a fixed distance to receive a reticle
#define cmdUNLK			"22"  // Unlock port
#define cmdWAFER		"23"  // Move elevator up/down to find next reticle
#define MAPLIST			"24"  //
#define cmdNULL			"99"  // no function byte
/* --------------- */

enum API {none,cVER,cSTAT,cIN,cGETOUT,cGETALROT,cGETWOBB,cGETERR,cSETCAR,cINIT,cSETOUT,cMAP,cGETL,cGETA,cPUT,cALIGN,cSETALROT,cPREWCup,cPREWCdown,cWC,cGETMAP,cGETFNRES,cUNLOAD,cLOAD,cSETLAMP,cSTARTMACRO,cSTOPMACRO,cSERVICE,cTWI,cGETSTATE};
//enum SMIF {sfNONE,sfSTAT,sfGETERR,sfSETCAR,sfINIT,sfINV,sfWGET,sfWPUTZ,sfGETMAP,sfUNLOAD,sfLOAD};
enum STAGE {nc,cPOS,cSETPOS,cSTATUS};
enum MIC {ncmic,mRESET,mGETPOS,mSETPOSZ};

QByteArray MPfull  = "0";
QByteArray MPempty = "1";
QByteArray MPmove  = "2";
QByteArray MPslow  = "3";

QSerialPort *serial_feeder;
QSerialPort *serial_stage;
QSerialPort *serial_mic;
QSerialPort *serial_log;
QSerialPort *serial_due;
QSerialPort *serial_api;
//QSerialPort *serial_smif;
QSerialPort *serial_smif2;

QString version;
QString IDstring    = "Machine ";  // Maschinen ID im Logfile
QString port;      // Port
QString portC;      // Port Feeder
QString portD;      // Port PA Data
QString portS;      // Port Stage
QString portM;      // Port Mikroskop
QString portP;      // Port Log
QString portA;      // Port Api
QString portSmif;   // Port SMIF
QString portSmif2;  // Port SMIF2
QStringList portlist;   // Liste der verfügbaren COM-Ports
QString fuiline;
QString cmdline;
QString suline;
QString outputDir   = "C:/INSBox/Plots";
QString hexDir      = "C:/INSBox/Service/scripts";
QString hexDir2     = "C:/INSBox/FW";
//QString argHexPC    = "C:\INSBox\FW\bin\avrdude \"-CC:\INSBox\FW\bin\avrdude.conf\" -v -V -patmega2560 -cwiring \"-PCOM17\" -b115200 -D \"-Uflash:w:C:\INSBox\FW\INS3000_TWI_PC.hex:i\"";
QString user;       // angemeldeter User
QString xcmdfile = "C:/INSBox/Servicetool/Files/";
QString macrofile = "C:/INSBox/Servicetool/Macros/";
QString progfile = "C:/INSBox/Service/scripts/";
QString SMIFlink = "C:/INSBox/Service/DOSBox-ASYST-ISIM.lnk";
QFile fuifile(xcmdfile + "FUI.txt");
QFile fuifilemacro(xcmdfile + "FUISensor.txt");
QFile fuifile1(xcmdfile + "FUI_POSABS.txt");
QFile fuifile2(xcmdfile + "FUI_SETVALUE.txt");
QFile fuifile3(xcmdfile + "FUI_GETVAL_PREA.txt");
QFile fuifile4(xcmdfile + "FUI_GETVAL_MOT.txt");
QFile fuifile5(xcmdfile + "FUI_GETVAL_SENS.txt");
QFile fuifile6(xcmdfile + "CMD_SENS.txt");
QFile fuifile7(xcmdfile + "CMD_MOT.txt");
QFile fuifile8(xcmdfile + "CMD_PREA.txt");
QFile fuifile9(xcmdfile + "FUI_SETVAL_SENS.txt");
QFile fuifile9_2(xcmdfile + "FUI_SETVAL_SENS_B8.txt");
QFile fuifile10(xcmdfile + "FUI_SETVAL_MOT.txt");
QFile fuifile11(xcmdfile + "FUI_SETVAL_PREA.txt");
QFile fuifile12(xcmdfile + "FUI_SETPARA_LIFT.txt");
QFile fuifile13(xcmdfile + "FUI_SETPARA_SENS.txt");
QFile fuifile14(xcmdfile + "FUI_SETPARA_PREA.txt");
QFile fuifile15(xcmdfile + "FUI_CAL_MOT.txt");
QFile fuifile16(xcmdfile + "FUI_CAL_SENS.txt");
QFile fuifile17(xcmdfile + "FUI_CAL_PREA.txt");
QFile sufile1(xcmdfile + "Files/1su.txt");
QFile sufile2(xcmdfile + "Files/2su.txt");
QFile sufile5(xcmdfile + "Files/5su.txt");
QFile sufile6(xcmdfile + "Files/6su.txt");
QFile sufile7(xcmdfile + "Files/7su.txt");
QFile sufile8(xcmdfile + "Files/8su.txt");
QFile sufile9(xcmdfile + "Files/9su.txt");
QFile cmdfile(xcmdfile + "Files/CMD.txt");
QByteArray usbdata;     // Container für seriell empfangene INSBox Daten
QByteArray usbAPIdata;     // Container für seriell empfangene INSBox Daten
QByteArray sersmif2data;// Container für seriell empfangene SMIF2 Daten
QByteArray mtdata;      // Container für seriell empfangene MotorController Daten
QByteArray senddata;
QByteArray lastxraccmd; // speichert letztes XRAC cmd für repeat send
QByteArray lastcmd;     // letzte gesendete CMD
QString errmess;
QByteArray EEPROM;      // INI-Daten an AVR
QByteArray line;        // enthält eine Zeile aus der geöffneten INI-Datei
QByteArray mtline;      // enthält eine Zeile aus der geöffneten Transfer-INI-Datei
QByteArray POS;         // enthält Positionswert als Array aus editierbaren Lines
QString mmaker[25];       // enthält macroliste
QString POS0;           // enthält Positionswert als String ohne Nullen
QString child;          // enthält den aktuellen Namen des Namen-Wert-Paares der Ini-Datei
QString FILE2OPEN;      // enthält den Namen und Pfad der SetupINI-Datei zum Öffnen
QString DATA2OPEN;      // enthält den Namen und Pfad der Testdaten-Datei zum Öffnen
QString MFILE2OPEN;     // enthält den Namen und Pfad der MotorINI-Datei zum Öffnen
QString MTFILE2OPEN;     // enthält den Namen und Pfad der MotorController INI-Datei zum Öffnen
QString HEXFILEOPEN;
QString HEXFILEOPEN2;
QString SMIFTYPE1;       // enthält den ausgelesenen SMIF Typ von Lift1
QString SMIFTYPE2;       // enthält den ausgelesenen SMIF Typ von Lift2
QString DEFAULTINIFILE  = "C:/INSBox/Feedersetup/Inssetup.INI";
QString tmpINIFILE      = "C:/INSBox/Feedersetup/Inssetup.tmp";
QString renameINIFILE   = "C:/INSBox/Feedersetup/Inssetup.0";
QString DEFAULTMOTFILE  = "C:/INSBox/Feedersetup/Insmotor.INI";
QString tmpMOTFILE      = "C:/INSBox/Feedersetup/Insmotor.tmp";
QString renameMOTFILE   = "C:/INSBox/Feedersetup/Insmotor.0";
QString DEFAULTMTFILE   = "C:/INSBox/Feedersetup/Transferpos.INI";
QString tmpMTFILE       = "C:/INSBox/Feedersetup/Transferpos.tmp";
QString renameMTFILE    = "C:/INSBox/Feedersetup/Transferpos.0";
QString s;
QString hSliderRed      = "QSlider::handle:horizontal {background: red;}";
QString hSliderBlue     = "QSlider::handle:horizontal {background: lightblue;}";
QString hSliderYello    = "QSlider::handle:horizontal {background: yellow;}";
QString spinRed         = "QSpinBox { border: 2px solid red; }";
QString spinBlack       = "QSpinBox { border: 0.5px solid grey; }";
QString backYello       = "background-color: yellow";
QString backLightYello  = "background-color: lightyellow";
QString backWhite       = "background-color: white";
QString backLightGreen  = "background-color: lightgreen";
QString backLightBlue   = "background-color: lightblue";
QString backLightRed    = "background-color: lightred";
QString backGrey        = "background-color: grey";
QString backDefault     = "background-color: rgb(255, 255, 255)";
QString backRed         = "background-color: red";
QString backLightGrey   = "background-color: lightgrey";
QString spinYelBlk      = "QSpinBox { border: 2px solid red; } QSpinBox {background-color: yellow;}";
QString col_Schiefergrau = "background-color: rgb(185,182,185)";
QString col_Beige       = "background-color: rgb(255,252,250)";
QString col_Beigeframe  = "background-color: rgb(251,248,246)";
QString col_Grey        = "background-color: rgb(243,243,243)";
QString col_greywhite   = "background-color: rgb(251,251,251)";
QString col_Saharasand  = "background-color: rgb(194,187,169)";
QString col_Pistazie    = "background-color: rgb(200,222,182)";
QString col_smartgreen  = "background-color: rgb(242,250,242)";
QString col_smartred    = "background-color: rgb(250,242,242)";
QString col_smartred2    = "background-color: rgb(255,235,235)";
QString radioGreen      = "QRadioButton::indicator {width: 10px;height: 10px;Background: lightgreen}";
QString radioRed        = "QRadioButton::indicator {width: 10px;height: 10px;Background: red}";
QString radioYello        = "QRadioButton::indicator {width: 10px;height: 10px;Background: yellow}";
QString radioGrey       = "QRadioButton::indicator {width: 10px;height: 10px;Background: grey}";
QString TabGrey         = "QTabBar::tab {border: 2px solid #C4C4C3;Background: lightgrey}";
QString TabGrey1        = "QTabWidget QTabBar::tab {background-color: #0f5d90;height: 50px; width: 50px;}";
QString TabGreen        = "QTabBar::tab {border: 2px solid #C4C4C3;Background: lightgreen}";
QString TabGreen1       = "QTabWidget::tab {Background: lightgreen;}";
QString node_break = "0";     //  globale variable für aktuelle Node für FN_break
QString motor_break = "0";    //  globale variable für aktuellen Motor für FN_break
QString abspostmp   = "0";
QPalette palBackground;
QPalette palBackground2;
QPalette palSchrift;
QPalette palSchrift0;
QVector<int> VECslot1(25);  // Liste der Slotbelegung Lift 1 in der Abfolge 1-25
QVector<int> VECslot2(25);
QVector<int> VECselslots1(25);
QVector<int> VECselslots2(25);
QVector<double> qv_x,qv_y,qv_x1,qv_y1,qv_x2,qv_y2;
QVector<double> qv_x_2,qv_y_2,qv_x1_2,qv_y1_2,qv_x2_2,qv_y2_2;
QByteArray tmpstr;      // serielle Service-CMDs
QByteArray testdaten[amount];   // serielle Testdaten an DUE schicken
int svc8;           // ScanMap
bool ok;               //
bool on;
bool svcresults;
bool motall;        // alle Motordatensätze geschrieben
bool svc0;          // Boardversionen
bool svc1;          // flatlen
bool svc2;          // wafsize
bool svc3;          // resetFlag
bool svc4;          // slitlen
bool svc5;          // setup displacement
bool svc6;          //
bool svc7;          //
bool svc9;          // get data
bool svc10;         // delay Flag
bool svc11;         // getwafangle
bool svc12;         // filter
bool svc13;         // FNidcorr
bool svc14;         // paangle
bool calSensHeight=0; // 1=calibration Sensor height1 aktiv
bool calSensHeight2=0; // 1=calibration Sensor height2 aktiv
bool multiwc;       // macro WC mehrfache Ausführung
bool swlogoff;      // Flag für Log AUS
bool swlogon;      // Flag für Log AN
bool svclog=0;      // 1=Buserrlog aktiv
bool errlog=0;      // 1=advanced errorlog aktiv
bool errlogwait=0;  // 1=advanced errorlog auschalten
bool r_logon=0;    // 1=advanced errorlog wieder anschalten
bool r_debuglog=0;     // Hilfsflag zur Reaktivierung des debug log
bool r_errlog=0;     // Hilfsflag zur Reaktivierung des error log
bool r_buslog=0;     // Hilfsflag zur Reaktivierung des bitbus log
bool r_warnlog=0;     // Hilfsflag zur Reaktivierung des warn log
bool APIactive;     // API CMDtype active
bool APIpassive;    // API CMDtype INFO
bool APIerr;        // API CMD error
bool APIsta;        // API CMD status
bool SMIFactive;     // SMIF CMDtype active
bool macroL1sens = 0;   // 1=macro lift1 sensor aktiv
bool macroL2sens = 0;   // 1=macro lift2 sensor aktiv
bool macro_profil = 0;
bool macro_decenter = 0;
bool macroclean = 0;    // 1=macro wafer detection aktiv
bool macrounitpos = 0;  // 1=macro unitpos aktiv
bool macromacro = 0;    // macromaker
bool makrostring = 0;       // 1=Makro Teststring aktiv
bool PAHmakrostring = 0;   // Makro PAH_AbsPos_X-string
bool PAPmakrostring = 0;   // Makro PAP_AbsPos_X-string
bool PARmakrostring = 0;   // Makro PAR_AbsPos_X-string
bool PATmakrostring = 0;   // Makro PAT_AbsPos_X-string
bool WCHmakrostring = 0;   // Makro WCH_AbsPos_X-string
bool WCPmakrostring = 0;   // Makro WCP_AbsPos_X-string
bool LDXmakrostring = 0;   // Makro LDX_AbsPos_X-string
bool LDYmakrostring = 0;   // Makro LDY_AbsPos_X-string
bool L1Hmakrostring = 0;   // Makro L1Height_AbsPos_X-string
bool L1Tmakrostring = 0;   // Makro L1Tilt_AbsPos_X-string
bool L2Hmakrostring = 0;   // Makro L2Height_AbsPos_X-string
bool L2Tmakrostring = 0;   // Makro L2Tilt_AbsPos_X-string
bool MIC_LOOP = 0;      // 1=MIC-Loop aktiv
bool micloopoff = 0;    // 1=MIC-loop abschließen
bool API_LOOP = 0;      // 1=API-LOOP aktiv
bool API_POLLTEST = 0;  // 1=API-POLLTEST aktiv
bool loopoff = 0;       // 1=API-loop abschließen
bool cmdAPI = 0;     // 1=APIcmd Response ausstehend
bool cmdASYSTlog = 0;// 1=ASYSTcmd Response ausstehend
bool cmdASYSTstat = 0;// 1=ASYSTcmd Response ausstehend
bool xyplot = 0;     // 1=XY-Plot aktiv
bool plotsqr = 0;    // 1=Umschalten auf TextLabel sqrlog
bool resetpw = 0;    // Passwörter neu setzen
bool pollflagDC = 0; // 1=DC polling aktiv
bool pollflagWS = 0; // 1=Wafer-/Liftsensor polling aktiv
bool pollflagTP = 0; // 1=Temperatur polling aktiv
bool pollflagPF = 0; // 1=Powerfail polling aktiv
bool pollflagMV = 0; // 1=Motor Voltage polling aktiv
bool pollflagAV = 0; // 1=analog Vac polling aktiv
bool pollflagVV = 0; // 1=Vac ventil polling aktiv
bool pollflagIO = 0; // 1=I/O ports polling aktiv
bool pollflagPS = 0; // 1=PA Sensor Meas polling aktiv
bool pollflagWO = 0; // 1=WobblerLamp polling aktiv
bool pollflagMS = 0; // 1=Mapping Sensor polling aktiv
bool pollflagEMO = 0; // 1=EMO polling aktiv
bool getAVoper=0;     // 1=analoge Vacuumwerte einmalig auslesen
bool getCarrSens1 = 0;
bool getCarrSens2 = 0;
bool cmdfeeder = 0;  // CMD-Block 1= Service CMD Response ausstehend
bool cmdapiflag = 0; // CMD-Block 1= API CMD Response ausstehend
bool stagecmd = 0;   // 1=auf Antwort pos von Stage warten
bool STAGECAL = 0;   // Flag Stagekalibrierung
bool miccmd = 0;     // 1=auf Antwort pos von MIC warten
bool res2pos = 0;   // 1=Aufruf Folgepositionierung der Achse auf Standardpos
bool cleanman = 0;  // 1=manuelles clean up aktiv
bool cleanaktiv = 0;// 1=eine Sequenz ist im Ablauf aktiv
bool stagetimer = 0; // 1=kein stage timeout
bool cleangetpos = 0;// 1=Achspositionenabfrage aktiv
bool LDvac2 = 0;     // 1=wartet auf send (cmdfeeder = 0)
bool PAvac2 = 0;     // 1=wartet auf send (cmdfeeder = 0)
bool WC1vac2 = 0;     // 1=wartet auf send (cmdfeeder = 0)
bool WC2vac2 = 0;     // 1=wartet auf send (cmdfeeder = 0)
bool CH4vac2 = 0;     // 1=wartet auf send (cmdfeeder = 0)
bool CH6vac2 = 0;     // 1=wartet auf send (cmdfeeder = 0)
bool CheckCH6vac = 0;   // 1=Checkbox CH6Vac ist checked
bool CH8vac2 = 0;     // 1=wartet auf send (cmdfeeder = 0)
bool CheckCH8vac = 0;   // 1=Checkbox CH8Vac ist checked
bool waitrepeat = 0;  // 1=wartet auf Rückmeldung und schaltet dann feeder-com aus
bool f_lift1xyhgt = 0;  // 1=vor Lift1 height wird LDY out gefahren
bool f_lift2xyhgt = 0;  // 1=vor Lift2 height wird LDY out gefahren
bool f_lift1operhgt = 0;  // 1=vor Lift1 height wird LDY out gefahren
bool f_lift2operhgt = 0;  // 1=vor Lift2 height wird LDY out gefahren
bool f_lift1senshgt = 0;  // 1=vor Lift1 height wird LDY out gefahren
bool f_lift2senshgt = 0;  // 1=vor Lift2 height wird LDY out gefahren
bool assistant_wc = 0;    // 1=Assistant Wafer changer ist aktiv
bool isWaf1 = 0;           // 1=wafer1
bool isWaf2 = 0;           // 1=wafer2
bool getliftpos2;          // 1=wait for pos
bool serialapi = 0;        // 1=serialAPI vom INSBox Servicetool geöffnet
bool apiloopcpl=0;         // 1=cyclusende
bool setfricbit=0;         // 1=LIFT Setupdaten nach CASS neu schreiben
bool apireset=0;           // 1=INSBox Reset is active
bool flat=0;               // 1=Wafer mit Flat
bool setpara=0;            // 1=SET_PARAM aktiv
bool getpara=0;            // 1=GET_PARAM aktiv
bool waitlog=0;           // 1=kettenbefehl aktiv
bool setvacdata=0;         //1=store vacdata to INSBox EPROM
bool setLock1data=0;       //1=store lock1data to INSBox EPROM
bool setLock2data=0;       //1=store lock2data to INSBox EPROM
bool loadcar=0;             //1=warten auf Respponse Load Carrier
bool getparam2=0;           //1=warten auf Reply of $GET_29
bool vactestflag=0;         //1= Vactest eingeschaltet
int makrostringstep = 0;   // Makro AbsPos_X-string step
int idxwaf = 0;           // Index des GET Wafers
int idxwaf1 = 0;          // index von wafer1 bei GET wafer2
int idxwaf2 = 0;          // index von wafer1 bei GET wafer2
int PAwaf = 99;            // Index des Wafers auf dem Aligner
int CHwaf = 99;            // Index des Wafers auf der Stage
int cleansequenz = 255;// nummer der aktiven Sequenz
uint16_t cmdid  = 0; // Index für Macro Profile
uint16_t svcid  = 0;
int zaehler;        // Zähler für Macro POS_ABS Zyklen
int countmacro = 0;  // Anzahl der Zeilen aus dem macro maker
int feedertimeout = 2000;
int APIcmdtimeout = 2000;
int stagecmdtimeout = 5000;
int fehler = 0;     // Fehlervariable
int cntraute = 0;    // Feedback gezählte Trennzeichen
int idxloop1;        // Index auf selektierte Slotnr Lift1
int idxloop2;        // Index auf selektierte Slotnr Lift2
int cnt;             // Cyclecounter
int job;             // 1 = ein Wafer befindet sich im Feeder
int casslift;        // setzt den selektierten Lift
int xsens;           // wird bei tab LIFT1 oder LIFT2 gesetzt und setzt die Cass-Radiobutton bei @SENSOR
int XRACcmd;         // leitet received data in Datenfelder für XRAC um
int XRACmot;         // 1= wartet auf Response der aktiven Motorparamter im RAC
int LIVEcmd;         // leitet received data in Datenfelder für LIVE Systemdaten um
int toggle;
int store;           // storeprozess aktiv
int partmot;         // Zähler für gesendete Motorparametersätze
int cntall;          // Zähler für Daten zwischen &-Trennzeichen
int cmdaktiv;        // 1=EESETUP, 2=EEMOT,
int rXcmd;           // switch für XRAC Alignerresponses
int waitACTpos;      // 1= warten auf Daten der Positionsabfrage
int waitLDout;       // 1= warten auf LDout Bestätigung
int waitaction;      // allg. für verkettete Aktionen
int repeat;          // 1= CMD kann wieder gesendet werden
int xrepeat;         // XCMD wird wiederholt wenn xrepeat=1
int ststore;         // 1=Ablauf Store Transferposition
int calsens;         // 1=auf Antwort calibrate Sensor lift1 warten
int calsens2;        // 1=auf Antwort calibrate Sensor lift2 warten
int twrblockrun = 0; // set Tower run pattern aktive
int twrblockcass = 0; // set Tower run pattern aktive
int twrblockstdby = 0; // set Tower run pattern aktive
int twrblocksvc = 0; // set Tower run pattern aktive
int twrblockerr = 0; // set Tower run pattern aktive
int twrblockalarm = 0; // set Tower run pattern aktive
int value;
int ampl;
int clear;
int clear_2;
int userindex = 0;    // 1=dev, 2=service, 3=setup, 4=prog, 5=oper
int boardno;
uint8_t mstep;
uint8_t mstep2;   // index für macromaker macro
int macro_anglecheck;
int macroaktiv_ld;
int testdata = 0;   // 1=Flag Testdata werden gesendet
int chart = 0;      // Flag für Chartdaten vorhanden
int cyclecount = 0;
int hextype;
int phase = 0;
int lastcheckbutton;
int apiid_copy;

float resoL1H;      // Resolution der Achse
float resoL1T;
float resoL2H;
float resoL2T;
float resoLDX;
float resoLDY;
float resoPAH;
float resoPAP;
float resoPAR;
float resoPAT;
float resoWCH;
float resoWCP;

QString anglestep;
QString len;
QString mu;
QString su;
QString CMD;
QString FUI;
QStringList setP;

QByteArray tempwc1;   // temporäre EEPROM Datenspeicher -> t_part_clear()
QByteArray tempwc2;
QByteArray tempwc3;
QByteArray tempwc4;
QByteArray tempwc5;
QByteArray tempwc6;
QByteArray tempwc7;
QByteArray tempwc8;
QByteArray tempwc9;
QByteArray tempwc10;
QByteArray tempwc11;
QByteArray tempwc12;
QByteArray tempwc13;
QByteArray tempwc14;
QByteArray tempwc15;
QByteArray tempwc16;
QByteArray tempwc17;
QByteArray tempwc18;
QByteArray tempwc19;
QByteArray tempwc20;
QByteArray tempwc21;
QByteArray tempwc22;
QByteArray tempwc23;
QByteArray tempwc24;
QByteArray tempwc25;
QByteArray tempwc26;
QByteArray tempwc27;
QByteArray tempwc28;
QByteArray tempwc29;
QByteArray tempwc30;
QByteArray tempwc31;
QByteArray tempwc32;
QByteArray tempwc33;
QByteArray tempwc34;
QByteArray tempwc35;
QByteArray tempwc36;
QByteArray tempwc37;
QByteArray tempwc38;
QByteArray tempwc39;
QByteArray tempwc40;
QByteArray tempwc41;
QByteArray tempwc42;

QByteArray mot[14][41];     // speichert alle 14 Motordatensätze

QByteArray bytedata1;
QByteArray bytedata2;
QByteArray bytedata3;
QByteArray bytedata4;
QByteArray bytedata5;
QByteArray bytedata6;
QByteArray bytedata7;
QByteArray bytedata8;
QByteArray bytedata9;
QByteArray bytedata10;
QByteArray bytedata11;
QByteArray bytedata12;
QByteArray bytedata13;
QByteArray bytedata14;
QByteArray bytedata15;
QByteArray bytedata16;
QByteArray bytedata17;
QByteArray bytedata18;
QByteArray bytedata19;

/* temporäre SETUP.INI-Werte für Konvertierung in mm */
int	Wafersens_height;
int	Unload_oper_height;
int	XY_Loader_height;
int	MeasUnit_Height;
int	Tilt_on_pos;
int	Tilt_off_pos;
int	LD_X_L1_pos;
int	LD_X_L2_pos;
int	LD_X_PA_free_pos;
int	LD_X_PA_pos;
int	LD_Y_L1_pos;
int	LD_Y_L2_pos;
int	LD_Y_PA_pos;
int	LD_Y_Outlift_pos;
int	PA_belowLO_height;
int	PA_belowLO_height_thin;
int	PA_LO_height;
int	PA_aboveLO_height_thin;
int	PA_aboveLO_height;
int	PA_height;
int	PA_CH_height;
int	PA_WO_angle;
int	PA_WO_rotpos;
int	PA_angle;
int	PA_Align2front;
int	WC_aboveCH_height_thin;
int	WC_aboveCH_height;
int	WC_Ch_height;
int	WC_belowCH_height;
int	WC_CH_free_height;
int	WC_Left_pos;
int	WC_mid_pos;
int	WC_right_pos;
int	WC_LO_height;
int	slot1;
int	Slotpitch;
int	Slotsizewdow;
int	Wafsizewdow;
int	WafOffset;
int	FingerOffset;
int graphcol;           // Flag für Farbe des Graphen Sensordaten
int graphcol_2;           // Flag für Farbe des Graphen Sensordaten

QGraphicsScene *scene;
QTimer *cmdtimeout;
QTimer *apitimeout;
QTimer *stagetimeout;
QTimer *syspoll;        // System-Daten pollen
QTimer *pollstat;
QTimer *polltimer;
QTimer *setSendTimer;
QTimer *cmdSTA;
QTimer *stageSTA;
QTimer *stageCAL;
QTimer *poll_IN;
QTimer *progEnd;
QTimer *macromaker;
QTimer *macrotest;
QTimer *APIlooptimer;
QTimer *delay;
QTimer *apitestpolling;
QTimer *vactest;

//Q_ENUMS(cmd)
//enum cmd { DC8, DC12, DCM12, DC24 };

#endif // SERVICE_H
