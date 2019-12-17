#ifndef KUKA_ROBOT_H
#define KUKA_ROBOT_H
// This material is the exclusive property of KUKA Roboter GmbH.
// Except as expressly permitted by separate agreement, this material may only
// be used by members of the development department of KUKA Roboter GmbH for
// internal development purposes of KUKA Roboter GmbH.
//
// Copyright (C) 2008 - 2015
// KUKA Roboter GmbH, Germany. All Rights Reserved.


//! \defgroup KERNEL_DLL Externe Schnittstellen der Kernel-System-DLL


//! \file
//! \ingroup KERNEL_DLL
//! \brief   Externer Schnittstellen-Header zur Darstellung eines (KUKA-)
//!          Roboters (�ber Maschinendaten) und Bereitstellung von Teilen der
//!          KRC-Funktionalit�t.


//<CL>
//*****************************************************************************
// Datum       Programmierer        Reviewer
//             Beschreibung
//-----------------------------------------------------------------------------
// 11.11.2008  Aurnhammer           keiner
//             Erstellung.
// 06.04.2009  Aurnhammer           Burkhart/Schreittmiller/Wiedemann (CI)
//             KernelSystem-DLL und Prototyp HFP-CP
// 06.11.2009  Aurnhammer          Burkhart/Sonner
//             �berarbeitung KernelSystem-DLL
// 24.11.2009  Parlow              Aurnhammer
//             Versionspr�fung KernelSystem-DLL
// 26.11.2009  Parlow              Aurnhammer/Burkhart
//             �bergangsl�sung zum Einlesen der MADAs einer V8.1
// 12.01.2010  Aurnhammer
//             Anpassungen f�r FrameVisu und VC++ 6.0
// 16.02.2010  Aurnhammer
//             Portierung der Testapplikation zur Kernel-DLL in die V8.1
// 10.03.2010  Sonner               Aurnhammer
//             $EXT_DYN_DAT f�r KernelDll zulassen.
// 25.03.2010  Aurnhammer          Wiedemann (CI)
//             Einf�hrung $SPL_VEL_MODE
// 09.04.2010  Aurnhammer           Burkhart
//             Lizensierung der KernelSystem-DLL
// 25.06.2010  Aurnhammer          Wiedemann
//             Optimierung der HFPCP-Profilplanung
// 20.08.2010  Aurnhammer           Tronnier
//             �bernahme verschiedener Daten aus den Madas
// 31.08.2010  Aurnhammer          Tronnier (CI)
//             Versionsnummern erh�ht
// 11.11.2010  Aurnhammer           Burkhart/Mez�si (CI)
//             CRDB46871: KernelSystem.dll kennt koppelbare Antriebe nicht.
// 09.02.2011  Burkhart            Aurnhammer/Wiedemann/Deller
//             Schreittmiller      Lebsack/Sturm
//             KERNEL-DLL: Schnittstellenredesign; Multiinstanzf�higkeit Spline;
//                         DLL-Integration in die KRC; Absolutgenauigkeit
// 15.02.2011  Burkhart            Schreittmiller
//             Codeinspektion KERNEL-DLL eingearbeitet
// 14.02.2011  Schreittmiller      Burkhart
//             �berarbeitung Doxygen-Dokumentare
// 23.02.2011  Aurnhammer          Wiedemann
//             CRDB47088: Unstetigkeit im Reibmodell beseitigen
// 10.03.2011  Aurnhammer          Burkhart
//             Initialisierung des Dynamikmodell korrigiert
// 30.03.2011  Sonner              Aurnhammer
//             Interfacefunktion f�r lineare Lastdatenidentifikation
// 27.05.2011  Aurnhammer          Burkhart
//             Bessere Behandlung der �berschleifkriterien
// 30.05.2011  Aurnhammer          Wiedemann
//             CRDB49359: Trafokonfig der Safety bei Transpressor oder WSH
//             CRDB49383: Falsches Dynamikmodell bei Winkelschr�ghand
// 20.07.2011  Aurnhammer          Wiedemann
//             Meldungshandling f�r Splinetestumgebung verbessert
// 05.10.2011  Schreittmiller      _PtpSplToBeReviewedByMP_
//             PTP-Spline Basisfunktionalit�t
// 05.10.2011  Burkhart            Deller
//             checkVersion, checkLicense und loadMADA vollst�ndig auf
//             Exceptions umgestellt
// 06.02.2012  Aurnhammer          _PtpSplToBeReviewedByMP_
//             Versionierung verfeinert
// 20.02.2012  Tronnier            Burkhart
//             $ECO_LEVEL und $CP_STATMON lesen und beschreiben.
// 27.02.2012  Schim
//             Groesse Meldungsstring erhoeht.
//             Meldungen direkt ueber setMsgNoAndText().
// 17.07.2012  Eisensehr           Burkhart, D�rndorfer
//             Integration des Maschinendatenladers in die KernelSystem-DLL.
// 30.08.2012  Aurnhammer          Tronnier
//             Umzug der MathLib nach BaseLib
// 31.10.2012  Tronnier            Aurnhammer
//             CRDB53782: "Schnittstelle KernelSystemDll ver�ndert"
// 15.02.2013  Aurnhammer          Burkhart
//             Dynamikmodell f�r Zusatzachsen im Spline
// 15.04.2013  Aurnhammer          Wiedemann
//             A4154: Kopplung externer Zusatzachsen im HFP/Dynamikmodell
// 20.08.2013  Tronnier            Steinke
//             A4121: S...REL f�r New Motion
// 07.02.2014  Aurnhammer          Burkhart
//             Vorw�rtstrafo um OriJoint-Modus erweitert
// 25.04.2014  Aurnhammer          Burkhart
//             CRDB60051: DH-Parameter f�r das schiefe Portal
// 20.10.2014  Aurnhammer          Wiedemann
//             Plattformmerge KRC/Sunrise (Team MP)
// 08.05.2015  Daniel Zicsi-Liess
//             Labs Plattformkonsolidierung:
//             checkVersion() entfernt
//             const bei checkLicense()
// 22.06.2015  Aurnhammer           Burkhart
//             Getrennte Versionierung von der MathLib im Plattformbranch im
//             Vergleich zum Rest der KernelDll
// 29.06.2015  Aurnhammer
//             Unbenutzte Fehlerkennung entfernt
// 24.07.2015  Heinig/Werling      Aurnhammer/Wiedemann
//             Erweiterung um Jacobimatrixberechnung
//*****************************************************************************
//</CL>


// Headerdateien
#include <stdio.h>
#include <list>
#include "dllBuildDefines.h"
#include "ml_MathLib.h"
#include "positionDescription.h"

//! \brief Versionsstring
//!
//! \attention
//! Bevor mit der KernelSystem-DLL gearbeitet werden kann, muss dieser Versionsstring
//! �ber die Methode checkVersion() durch die DLL auf Versionskompatibilit�t
//! gepr�ft werden
#define kernelDllVersionString "VERSION_KERNELDLL_(SW8.3)_13.00.00"

//! \brief Versionsnummer: Verwendung als "xx.xx.xx" (z.B. 12.02.03 = 0x00120203)
#define KRC_ROBOT_VERSION_NUMBER   0x00150714

// Versionspr�fungen
#if KRC_ROBOT_VERSION_NUMBER != KRC_POSITION_VERSION_NUMBER
   #error KukaRobot.h does not fit to positionDescription.h
#endif

// Konstanten, (Vorw�rts-) Deklarationen und Defines

//! /brief   Entspricht der KRL-Aufz�hlung \code ROTSYS #AS_TRA, #TCP, #BASE \endcode
enum ERotSys
{
   ROTSYS_AS_TRA = 1,
   ROTSYS_TCP,
   ROTSYS_BASE,
   ROTSYS_AS_GLOBAL
};


//! \brief   Entspricht der KRL-Aufz�hlung \code IPO_MODE #BASE, #TCP \endcode.
enum EIpoMode
{
   IPO_MODE_BASE,
   IPO_MODE_TCP
};


enum EEcoLevel
{
   ECO_LEVEL_OFF = 1,
   ECO_LEVEL_LOW,
   ECO_LEVEL_MIDDLE,
   ECO_LEVEL_HIGH
};


enum ECpStatmon
{
   CP_STATMON_NONE = 1,
   CP_STATMON_CHECK_S,
   CP_STATMON_CHECK_TS
};


//! \brief   Entspricht der KRL-Aufz�hlung \code SPLINE_PARA_VARIANT
//!          DEFAULT, COMMON, SEPARATE \endcode.
enum ESplineParaVariant
{
   SPLINE_PARA_VARIANT_DEFAULT,
   SPLINE_PARA_VARIANT_COMMON,
   SPLINE_PARA_VARIANT_SEPARATE
};


//! \brief   Werkzeugsto�richtung
enum EToolDirection
{
   AXIS_OF_COORDINATES_X = 1,
   AXIS_OF_COORDINATES_Y,
   AXIS_OF_COORDINATES_Z
};


//! \brief   Enum f�r CRobotBase Konstruktor zwecks Anbindung an die KRC
enum EKrcRunType
{
   LINK_TO_MAIN_RUN,    //!< Hauptlauf
   LINK_TO_ADVANCE_RUN  //!< Vorlauf
};


//! \brief   Entspricht den m�glichen \$AXIS_TYPE Werten der KRC gem�� Maschinendaten
enum EAxType
{
   AX_TYPE_LINEAR   = 1,  //!< Linear
   AX_TYPE_SPINDLE  = 2,  //!< Spindel
   AX_TYPE_ROTATORY = 3,  //!< Rotatorisch
   AX_TYPE_FINITE   = 4,  //!< Endlich
   AX_TYPE_ENDLESS  = 5   //!< Endlos
};


//! \brief   R�ckgabewerte der implementierten Methoden
enum ROBOT_RETVAL
{
   ROBOT_INPUTS_INVALID = -5,                //!< Ung�ltige oder unvollst�ndige Eingangsdaten
   ROBOT_TRANSFORMATION_NOT_CONFIGURED = -4, //!< Trafo nicht konfiguriert
   ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED = -3,  //!< Dynamik Modell nicht konfiguriert
   ROBOT_MADA_INVALID = -2,                  //!< Maschinendaten ung�ltig
   ROBOT_ERROR   = -1,                       //!< Ein Fehler ist aufgetreten
                                             //!< (z.B. ung�ltige Uebergabeparameter)
   ROBOT_OK      =  0                        //!< Alles in Ordnung
};


//! \brief   Setzbare Werte f�r die Berechnung der inversen Dynamik
enum HFP_CALC_MODE
{
   HFP_CALC_MOM        = 1, //!< Momente berechnen
   HFP_CALC_ENERGY     = 2, //!< Energie berechnen
   HFP_AD_FACTORS      = 4  //!< AD-Faktoren verwenden
};


//! \brief   Setzbare Optionen f�r die Berechnung der direkten Dynamik
enum HFP_CALC_OPT
{
   HFP_CALC_STATIC = 1, //!< Statische Anteils (Gravitation + Gewichtsausgleich) berechnen
   HFP_CALC_COR    = 2, //!< Zentrifugal- und Corioliskr�fte berechnen
   HFP_CALC_MASS   = 4  //!< Massenmatrix berechnen
};

//! \brief Bewegungskennung f�r die R�ckw�rtstrafo
enum ETrafoMode
{
   TRAFO_PTP_PKT = 0,         //!< Transformationsaufruf bei PTP
   TRAFO_CP_SPKT = 1,         //!< Transformationsaufruf bei CP-St�tzpunkt
   TRAFO_CP_EPKT = 2,         //!< Transformationsaufruf bei CP-Endpunkt
   TRAFO_CP_ORI_JOINT = 3,    //!< Transformationsaufruf f�r OriJoint
   TRAFO_CP_SINGULAR_PKT = 4, //!< Transformationsaufruf in Singularit�t mit Aufl�sen der Merhdeutigkeit
   TRAFO_CP_SINGULAR_SPKT = TRAFO_CP_SPKT|TRAFO_CP_SINGULAR_PKT,
   TRAFO_CP_SINGULAR_EPKT = TRAFO_CP_EPKT|TRAFO_CP_SINGULAR_PKT,
   TRAFO_CP_SINGULAR_ORI_JOINT = TRAFO_CP_ORI_JOINT|TRAFO_CP_SINGULAR_PKT,
   TRAFO_CP_JOG = 10          //!< Transformationsaufruf w�hrend Kartesischen Handverfahrens
};

//! \brief   Beschreibung eines Roboters durch Maschinendaten.
class CRobotInternals;

//! \brief Daten des Dynamikmodell
struct Robdyndat;

//! \brief Diese Klasse kapselt Grundsystemmeldungen (Meldungsdatenbank bzw.
//!        Message Manager) die innerhalb der Kernel-DLL abgesetzt wurden.
//!
//! Meldungen k�nnen maximal drei Parameter (Integer oder Strings) besitzen.
//! Liefert ein CRobot(Base) Objekt eine Fehlerkennung zur�ck, so kann man
//! �ber CRobotBase::getLatestMessage das zugeh�rige Fehlerobjekt (vom Typ
//! CKrcMessage) anzeigen lassen.
class _DLL_ CKrcMessage
{
   public:

      //! Maximale L�nge des Meldungskurztextes
      enum { MAX_MESSAGE_STR_LEN = 40 };

      //! Maximale L�nge eines Stringparameters einer Meldung
      enum { MAX_PARAM_STR_LEN = 160 };

      //! Maximale Parameteranzahl einer Meldung
      enum { MAX_PARAM_CNT = 3 };

      //! M�gliche Typen der Meldungsparameter
      enum EParamType
      {
         PARAM_TYPE_UNDEFINED,  //!< Parameter nicht definiert
         PARAM_TYPE_INT,        //!< Integerparameter
         PARAM_TYPE_STRING,     //!< Stringparameter
      };

      //! \name Interna
      //! Methoden f�r interne Zwecke
      //! @{
      //! Default Konstruktor
      CKrcMessage();

      //! \brief Meldung vorinitialisieren
      void init();

      //! \brief Interne Meldungskennung in externe Meldungsnummer und Kurztext
      //!        umwandeln
      //! \param[in] InternalMsgID  Interne MeldungsID
      void setKrcMsgNo(int InternalMsgID);

      //! \brief Meldungsnummer und Kurztext fuer Nicht-KRC-Meldungen setzen
      void setMsgNoAndText(int nMsgNo, const char strText[]);

      //! \brief Interne Hilfsfunktion f�r Verwalung (Setzen) von Zustandsmeldungen
      //! \param[in] StateMsgNo  Spezialkennung f�r Zustandmeldungen
      void setInternalStateMsgNo(unsigned short StateMsgNo);

      //! \brief Interne Hilfsfunktion zur Abfrage der internen Zustandsmeldungskennung
      //! \return Spezialkennung der Zustandmeldungen
      unsigned short getInternalStateMsgNo();

      //! \brief Setzen des Stringparameters param mit Index paramNo
      //! \param[in] paramNo Index des Stringparameters (beginnend bei 0)
      //! \param[in] param   Wert des Stringparameters
      //! \retval false  unzul�ssiger Index (>= MAX_PARAM_CNT)
      //! \retval true   param erfolgreich eingetragen
      bool setParam(unsigned int paramNo, const char* param);

      //! \brief Setzen des Integerparameters param mit Index paramNo
      //! \param[in] paramNo Index des Integerparameters (beginnend bei 0)
      //! \param[in] param   Wert des Integerparameters
      //! \retval false  unzul�ssiger Index (>= MAX_PARAM_CNT)
      //! \retval true   param erfolgreich eingetragen
      bool setParam(unsigned int paramNo, int param);
      //! @}


      //! Abfragen von Meldungsnummer, deutschem Kurztext und Meldungsparametern
      //! gem�� Meldungsdatenbanke bzw. Message Manager
      //! @{

      //! \brief Globale Meldungsnummer abfragen
      //! \return Globale Meldungsnummer (-1 bei uninitialisierter Meldung)
      int getKrcMsgNo() const
      {
         return KrcMsgNo;
      }

      //! \brief Deutschen Kurztext abfragen
      //! \retval "No message available." bei nicht initialisierter Meldung
      //! \retval Kurztext in deutsch
      const char* getKrcMsgShortTxt() const
      {
         return &(ShortedMsgTxt[0]);
      }

      //! \brief Parametertyp abfragen
      //! \param[in] paramNo Index des Parameters (beginnend bei 0)
      //! \retval Parametertyp
      //! \retval PARAM_TYPE_UNDEFINED bei Parameter Nummer >= MAX_PARAM_CNT
      EParamType getParamType(unsigned int paramNo) const;

      //! \brief Stringparameter mit Index "paramNo" abfragen
      //! \param[in] paramNo Index des Parameters (beginnend bei 0)
      //! \retval Parameterstring
      //! \retval NULL bei unzul�ssigem Index oder bei Integerparametern
      const char* getStringParam(unsigned int paramNo) const;

      //! \brief Integerparameterschl�ssel "param" abfragen
      //!
      //! \attention
      //!  Der Integerparameter param stellt nicht direkt den Wert des Parameters
      //!  wie in der entsprechenden KRC-Meldung dar. Stattdessen liefert er nur
      //!  einen Datenbankschl�ssel, �ber den die KRC den letztlich angezeigten
      //!  Meldungsparameter erst generiert (dieser Mechanismus wird in der DLL
      //!  derzeit leider noch nicht unterst�tzt). Bei Bedarf kann man aber in
      //!  der Datei C:/KRC/Data/CrossMeld.kxr (via TextEditor) nachsehen, was
      //!  hinter dem Schl�ssel letztlich steckt (dazu einfach nach "P_<param>"
      //!  suchen. Bspeispiel:
      //!                param   => Schl�ssel   =>  Eintrag in KRC Meldung
      //!                [0-5]   =>  P_[0-5]    =>     A[1-6]
      //!                [6-11]  =>  P_[6-11]   =>     E[1-6]
      //!                 63     =>   P_63      =>     CDIS
      //!
      //! \param[in]  paramNo Index des Parameters (beginnend bei 0)
      //! \param[out] param   Schl�ssel in die Parameterdatenbank
      //! \retval true fals param gesetzt werden konnte
      //! \retval false bei unzul�ssigem Index oder bei Stringparametern
      bool getIntParam(unsigned int paramNo, int& param) const;

      //! \brief Globale Meldungsnummer und deutschen Kurztext auf Konsole ausgeben
      void print(bool bPrintParams = false);
      //! @}

   private:

      //! Externe Meldungsnummer gem�� Meldungsdatenbank:
      int KrcMsgNo;
      //! Interne (eindeutige) Verwaltungsnummer f�r Zustandsmeldungen
      unsigned short InternalStateMsgNo;
      //! Shorted message text (in german):
      char ShortedMsgTxt[MAX_MESSAGE_STR_LEN];
      //! Parametertyp f�r bis zu MAX_PARAM_CNT Parameter
      EParamType _paramType[MAX_PARAM_CNT];
      //! Feld f�r bis zu MAX_PARAM_CNT Stringparameter
      char _stringParam[MAX_PARAM_CNT][MAX_PARAM_STR_LEN + 1];
      //! Feld f�r bis zu MAX_PARAM_CNT Integerparameterschl�ssel
      int _intParam[MAX_PARAM_CNT];
};

//! \brief   Kapselung eines Roboterteilobjekts (nur Lesezugriff) nach au�en.
//!
//! Diese Basisklasse umfasst alle grundlegenden Methoden, um
//! \li  Madas eines Roboterobjekt auszulesen,
//! \li  die Trafo eines Roboters zu rechnen und
//! \li  das Dynamik-Modell eines Roboters auszuwerten.
//!
//! \attention
//! Objekte dieser Klasse k�nnen ausschlie�lich innerhalb der KRC (vxWorks)
//! angelegt werden. Insbesondere bringt diese Objekt KEINEN eigenst�ndigen
//! Madalader mit! Statt dessen docken es sich direkt an den auf der KRC
//! projektierten Roboter an:
//! \li Dies kann wahlweise im Vorlauf- oder Hauptlaufkontext erfolgen.
//! \li Das dahinter stehende Roboterobjekt kann nicht modifizert werden
//!     (so k�nnen z.B. weder Tool noch Base gesetzt werden).
//! Au�erhalb der KRC definert diese Klasse (als Basisklasse) einen Teil
//! der Schnittstellen der abgeleiteten CRobot-Klasse.

class _DLL_ CRobotBase
{
   protected:

      //! Interne Repr�sentation des Roboters
      CRobotInternals *Internals;
      friend class CRobotInternals;

      //! \brief Default- und Copykonstruktor sowie Wertzuweisung sind verboten
      //! @{
      CRobotBase();
      CRobotBase(const CRobotBase& Dummy);
      CRobotBase& operator=(const CRobotBase& Dummy);
      //! @}

      //! \brief Wandelt externe Achswerte (Grad bzw. mm) in interne Werte (rad bzw. m) um
      //!
      //! \param[in]  Ks        Achstyp 0 = translatorisch, sonst rotatorisch
      //! \param[in]  ExtValue  externer Achswert in Grad bzw. mm
      //! \param[out] IntValue  interner Achswert in rad bzw. m
      void convertJointValuesExt2Int(int Ks, const double &ExtValue, double &IntValue) const;

      //! \brief Berechnet zur gegebenen Gelenkstellung q die Jacobimatrix J(q) im entsprechenden Koordinatensystem. 
      //! \brief Hinweis: Diese Methode wird von einer gleichnamigen Methode aufgerufen, die die Dynamikkonfiguration
      //! \brief aus der interne Repraesentation des Roboters benutzt - andere Dynamikkonfigurationen sind aber moeglich.
      //! \brief 
      //! \brief Dabei ist q in KernelDLL-Notation angegeben (Grad, Achsreihenfolge ROB_ACHS 1...6, EXT_ACHS 1...6).
      //! \brief Die Matrix ist wie folgt aufgebaut:<br>
      //! \brief                            ROB_ACHS 1  ...  ROB_ACHS 6      EXT_ACHS 1 ... EXT_ACHS 6
      //! \brief   Translations�nderung x        
      //! \brief   Translations�nderung y  
      //! \brief   Translations�nderung z 
      //! \brief   Rotations�nderung um x
      //! \brief   Rotations�nderung um y
      //! \brief   Rotations�nderung um z
      //! \brief
      //! \brief Die Achsreihenfolge entspricht der KernelDLL-Notation (MAX_ROB_ACHS Roboterachsen + MAX_EXT_ACHS Zusatzachsen), sofern nicht der 
      //! \brief Parameter "calculateKinematicChainJacobi == true" gesetzt wird.
      //!
      //! \param[in] rob Dynamikkonfiguration
      //! \param[in] q[MAX_ACHS] Achsstellung des Roboters (in Grad), maximal MAX_ACHS Achsen
      //! \param[in] tool Toolframe mit Translation in Millimetern
      //! \param[out] J[6xMAX_ACHS] Jacobimatrix Einheiten [m/s bzw. rad/s]
      //! \param[in] toolToWorldJacobi Optional: Parameter zur Berechnung der Jacobimatrix im <b>Tool</b> Koordinatensystem (default ist: <b>Basissystem der dynamischen Kette</b> // false)
      //! \param[in] calculateKinematicChainJacobi Optional: Falls true entspricht die Achsreihenfolge der in Chaindata.xml angegebenen (default ist: false)
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateJacobian(Robdyndat *rob, const double (&q)[MAX_ACHS], ml_CFrame &tool, double (&J)[6][MAX_ACHS], bool toolToBaseJacobi = false, bool calculateKinematicChainJacobi = false);

      //! \brief Berechnet die Jacobimatrix (Details siehe oben). Einziger Unterschied zur anderen calculateJacobian Methode: Es muss kein Toolframe �bergeben werden,
      //! \brief das globale Toolframe wird verwendet.
      //! \brief Hinweis: Diese Methode wird von einer gleichnamigen Methode aufgerufen, die die Dynamikkonfiguration
      //! \brief aus der interne Repraesentation des Roboters benutzt - andere Dynamikkonfigurationen sind aber moeglich.
      ROBOT_RETVAL calculateJacobian(Robdyndat *rob, const double (&q)[MAX_ACHS], double (&J)[6][MAX_ACHS], bool toolToBaseJacobi = false, bool calculateKinematicChainJacobi = false);

      //! \brief Berechnet Rotationen und Translationen der einzelnen Achsen der Roboterkette. Die Reihenfolge der
      //! \brief Matrizen bzw. Vektoren entspricht dabei der Reihenfolge in der Kette und nicht dem Achsindex.
      //! \brief Hinweis: Diese Methode wird von einer gleichnamigen Methode aufgerufen, die die Dynamikkonfiguration
      //! \brief aus der interne Repraesentation des Roboters benutzt - andere Dynamikkonfigurationen sind aber moeglich.
      //!
      //! \param[in] rob Dynamikkonfiguration
      //! \param[in]  q[MAX_ACHS] Achsstellung des Roboters (in Grad/mm), maximal MAX_ACHS Achsen
      //! \param[out] R[MAX_ACHS][3][3] Array von 3x3-Rotationsmatrizen f�r alle Achsen der Kette
      //! \param[out] s[MAX_ACHS][3] Array von 3x1-Translationsvektoren f�r alle Achsen der Kette
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateTransformationMatrix(Robdyndat *rob, const double (&q)[MAX_ACHS], double (&R)[MAX_ACHS][3][3], double (&s)[MAX_ACHS][3]);

      //! \brief Berechnet Frames von Fusspunkt der dynamischen Kette zu jeder Achse bzw. bei letzter Achse bis zum Tool. 
      //! \brief die Funktion ber�cksichtigt die Achsreihung der kinematischen Kette aus der
      //! \brief ChainData.xml.
      //! \brief Hinweis: Diese Methode wird von einer gleichnamigen Methode aufgerufen, die die Dynamikkonfiguration
      //! \brief aus der interne Repraesentation des Roboters benutzt - andere Dynamikkonfigurationen sind aber moeglich.
      //!
      //! \param[in] rob Dynamikkonfiguration
      //! \param[in] q[MAX_ACHS] Achsstellung des Roboters (in Grad), maximal MAX_ACHS Achsen
      //! \param[in] tool Toolframe erlaubt das Berechnen der Jacobimatrix f�r beliebige Tools ohne Seiteneffekte
      //!                 Einheit des Translationsteils sind [m]
      //! \param[out] frameArray[MAX_ACHS] Array von ml_CFrames von Base zu jeder Achse bzw. f�r letzte Achse zum Tool
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateFrameMatrix(Robdyndat *rob, const double (&q)[MAX_ACHS], const ml_CFrame &tool, ml_CFrame (&frameArray)[MAX_ACHS]);
      

      //! \brief Berechnet Frames vom Tool zu jeder Achse, wobei die Funktion die Achsreihung der kinematischen Kette
      //! \brief aus der ChainData.xml ber�cksichtigt.
      //! \brief Hinweis: Diese Methode wird von einer gleichnamigen Methode aufgerufen, die die Dynamikkonfiguration
      //! \brief aus der interne Repraesentation des Roboters benutzt - andere Dynamikkonfigurationen sind aber moeglich.
      //!
      //! \param[in] rob Dynamikkonfiguration
      //! \param[in] q[MAX_ACHS] Achsstellung des Roboters (in Grad), maximal MAX_ACHS Achsen
      //! \param[in] tool Toolframe erlaubt das Berechnen der Jacobimatrix f�r beliebige Tools ohne Seiteneffekte
      //!                 Einheit des Translationsteils sind [m]
      //! \param[out] frameArray[MAX_ACHS] Array von ml_CFrames von Tool zu jeder Achse
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateFrameMatrixTool(Robdyndat *rob, const double (&q)[MAX_ACHS], const ml_CFrame &tool, ml_CFrame (&frameArray)[MAX_ACHS]);

   public:

      //! \brief Modulversion gegen KernellSystem-DLL Version pr�fen
      //!
      //! Bei Versionskonflikten wird eine MadaInternalErrorExc Exception geworfen
      //! mit Infos zur Modul-Version und zur DLL-Version.
      //!
      //! \param[in] versionString String des Moduls, welches Funktionen der KernellSystem-DLL
      //!                          verwendern will im Format
      //!                          "\n\nVERSION_MODUL_(SW8.3)_01.00.00\n\n"
       static void checkKernelSystemDllVersion(char* versionString);
  
      //! \brief Einzig zul�ssiger CRobotBase Konstruktor
      //!
      //! \attention
      //! Ein Objekt dieses Typs kann nur innerhalb der KRC (unter vxWorks)
      //! existieren. Dabei dockt es sich im Vorlauf- oder Hauptlaufkontext an
      //! den derzeit projektierten Roboter an.\n
      //!
      //! Au�erhalb der KRC wirft dieser Konstruktor die MadaInternalErrorExc
      //! Exception.
      //!
      //! \param[in] RunType  Kennung, ob sich dieses Objekt an den Vorlauf oder
      //!                     Hauptlauf der KRC andocken soll (kann au�erhalb
      //!                     dieses Konstruktors nicht mehr ge�ndert werden!)
      CRobotBase(EKrcRunType RunType);

      //! \brief Destruktor
      virtual ~CRobotBase();

      //! \brief Lizenzpr�fung der KernellSystem-DLL
      //!
      //! \attention
      //! Ohne g�ltige Lizenz wird eine MadaInternalErrorExc Exception geworfen.
      //! Die KernellSystem-DLL kann ohne g�ltige Lizenz keine Madas laden.
      //!
      //! \param[in] licensePath  Pfad zum Verzeichnis in dem das Lizenzfile
      //!                         "KernelSystem.lic" liegt
      void checkLicense(const char *licensePath);

      //! \brief Pr�fen der Maschinendaten auf G�ltigkeit
      //!
      //! \retval true   Maschinendaten g�ltig
      //! \retval false  Maschinendaten ung�ltig
      virtual bool isMadaValid() const;

      //! \brief Pr�fen, ob die Trafo verf�gbar ist.
      //!
      //! \retval true   Trafo verf�gbar
      //! \retval false  Trafo nicht verf�gbar
      virtual bool isTrafoConfigured() const;

      //! \brief Pr�fen, ob die absolutgenaue Trafo verf�gbar ist.
      //!
      //! \retval true   absolutgenaue Trafo verf�gbar
      //! \retval false  absolutgenaue Trafo nicht verf�gbar
      bool isAbsAccurTrafoAvailable() const;

      //! \brief Pr�fen, ob das Dynamik Modell konfiguriert ist
      //!
      //! \retval true   Dynamik Modell verf�gbar
      //! \retval false  Dynamik Modell nicht verf�gbar
      virtual bool isDynamicModelConfigured() const;

      //! \brief   Aktualisierung der internen Roboterdarstellung (wirkt nur bei
      //!          CRobotBase). Legt die zum Hauptlauf/Vorlauf zugeh�rige Frame-
      //!          umgebung sowie die Lastdaten intern als Kopie ab. Lesende
      //!          Zugriffe auf diese Daten liefern dann immer in sich konsistente
      //!          Werte (der letzen Kopie)
      //!
      //! \retval  ROBOT_MADA_INVALID Maschinendaten ung�ltig.
      //! \retval  ROBOT_OK           Kein Fehler
      ROBOT_RETVAL update();

      //! \brief   Interpolationstakt in [sec] lesen.
      //!
      //! \param[out]  TIpo      Interpolationstakt in [sec]
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK           Kein Fehler
      ROBOT_RETVAL getInterpolationCycle(double& TIpo);

      //! \brief Robotertyp auslesen
      //!
      //! \param[out] TrafoName    String des Robotertyps (in KRL: CHAR \$TRAFONAME[66])
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK           Kein Fehler
      ROBOT_RETVAL getTrafoName(char TrafoName[66]);

      //! \brief   Bitfeld der aktiven Achsen auslesen.
      //!
      //! \param[out] AxisMask  Bitfeld der aktiven (d.h. gem�� Maschinendaten
      //!                       korrekt projektierten) Achsen
      //!                       - Roboterachsen: A1 (Bit 0), ..., A6 (Bit 5)
      //!                       - Zusatzachsen:  E1 (Bit 6), ..., E6 (Bit 11)
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK           Kein Fehler
      ROBOT_RETVAL getActiveAxis(int& AxisMask);

      //! \brief   \$SPTP_EXAX_PARA lesen
      //!
      //! \param[out]  ExAxPara  Parametrisierungseinstellung
      //!
      //! \retval     ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK            Kein Fehler
      ROBOT_RETVAL getSptpExAxPara(ESplineParaVariant (&ExAxPara)[6]);

      //! \brief    \$TOOL lesen.
      //!
      //! \param[out]  Tool      Tool-Frame
      //!
      //! \retval     ROBOT_TRANSFORMATION_NOT_CONFIGURED  Keine Trafo konfiguriert
      //! \retval     ROBOT_ERROR   Kein g�ltiges Tool gefunden
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL getTool(ml_CFrame& Tool);

      //! \brief Werkzeugsto�richtung lesen (nur bei Spline relevant)
      //!
      //! \param[out] ToolDirection       Sto�richtung
      //!
      //! \retval     ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK            Kein Fehler
      ROBOT_RETVAL getToolDirection(EToolDirection& ToolDirection);

      //! \brief    \$BASE lesen.
      //!
      //! \param[out]  Base      Base-Frame
      //!
      //! \retval     ROBOT_TRANSFORMATION_NOT_CONFIGURED  Keine Trafo konfiguriert
      //! \retval     ROBOT_ERROR    Kein g�ltiges Base gefunden.
      //! \retval     ROBOT_OK       Kein Fehler
      ROBOT_RETVAL getBase(ml_CFrame& Base);

      //! \brief Ipo-Mode auslesen
      //!
      //! \param[out] IpoMode      Enum mit IpoMode (\$IPO_MODE)
      //!
      //! \retval     ROBOT_TRANSFORMATION_NOT_CONFIGURED  Keine Trafo konfiguriert
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL getIpoMode(EIpoMode& IpoMode);

      //! \brief \$ECO_LEVEL auslesen.
      //!
      //! \param[out]  ecoLevel Referenz in die \$ECO_LEVEL geschrieben wird.
      //! \retval      ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval      ROBOT_OK      Kein Fehler
      ROBOT_RETVAL getEcoLevel(EEcoLevel& ecoLevel);

      //! \brief \$CP_STATMON auslesen.
      //!
      //! \param[out]  cpStatmon Referenz in die \$CP_STATMON geschrieben wird.
      //! \retval      ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval      ROBOT_OK      Kein Fehler
      ROBOT_RETVAL getCpStatmon(ECpStatmon& cpStatmon);

      //! \brief Holen des Typs einer Achse
      //!
      //! \attention
      //! \li Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //!     geladen worden sein.
      //! \li Der gelieferte Achstyp Enum entspricht numerisch genau dem zugeh�rigen
      //!     Wert von \$AXIS_TYPE in den Madas.
      //!
      //! \param[in]  axIdx        Index der Achse (0 <= axIdx < 12)
      //! \param[out] axType       Achstyp der angefragten Achse
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeprameter unzul�ssig
      //! \retval     ROBOT_ERROR           Uninitialisierter Achstyp
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getAxisType(int axIdx, EAxType& axType);

      //! \brief Holen der maximalen kartesischen Geschwindigkeit
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pVel       maximale kartesische Geschwindigkeit [mm/s]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxVelCP(double *pVel);

      //! \brief Holen der maximalen Schwenkgeschwindigkeit
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pVel       maximale Schwenkgeschwindigkeit [�/s]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxVelOri1(double *pVel);

      //! \brief Holen der maximalen Drehgeschwindigkeit
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pVel       maximale Drehgeschwindigkeit [�/s]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxVelOri2(double *pVel);

      //! \brief Holen der maximalen kartesischen Beschleunigung
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pAcc       maximale kartesische Beschleunigung [mm/s^2]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxAccCP(double *pAcc);

      //! \brief Holen der maximalen Schwenkbeschleunigung
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pAcc       maximale Schwenkbeschleunigung [�/s^2]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxAccOri1(double *pAcc);

      //! \brief Holen der maximalen Drehbeschleunigung
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pAcc       maximale Drehbeschleunigung [�/s^2]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxAccOri2(double *pAcc);

      //! \brief Holen des maximalen kartesischen Ruck
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pJerk       maximaler kartesischer Ruck [mm/s^3]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxJerkCP(double *pJerk);

      //! \brief Holen des maximalen Orientierungsruck
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pJerk       maximaler Orientierungsruck [�/s^3]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxJerkOri(double *pJerk);

      //! \brief Holen der maximalen Motorgeschwindigkeit am Abtrieb vor
      //!        Achskopplung, d.h
      //!        \li \b nach Einrechnung der �bersetzung \$RAT_MOT_AX,
      //!        \li aber noch \b vor \$COUP_COMP, \$EXCOUP_COMP
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] maxVel       maximale Achsgeschwindigkeit [�/s] bzw. [mm/s]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeprameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxMotVelPostRatMotAx(int axIdx, double* maxVel);

      //! \brief Holen des �berwachungsfaktors zur Sollgeschwindigkeit
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pVelActMa    �berwachungsfaktor in [\%]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getVelActMa(double *pVelActMa);

      //! \brief Holen der maximalen Motorbeschleunigung am Abtrieb vor
      //!        Achskopplung, d.h
      //!        \li \b nach Einrechnung der �bersetzung \$RAT_MOT_AX,
      //!        \li aber noch \b vor \$COUP_COMP, \$EXCOUP_COMP
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] maxAcc       maximale Achsbeschleunigung [�/s^2] bzw. [mm/s^2]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeprameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxMotAccPostRatMotAx(int axIdx, double* maxAcc);

      //! \brief Holen des �berwachungsfaktors zur Sollbeschleunigung
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] pAccActMa    �berwachungsfaktor in [\%]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getAccActMa(double *pAccActMa);

      //! \brief Holen des maximalen Achsrucks einer Achse
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] maxJerk      maximaler Achsruck [�/s^3] bzw. [mm/s^3]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeparameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxAxisJerk(int axIdx, double* maxJerk);

      //! \brief Holen des maximalen Getrieberucks einer Achse
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] maxJerk      maximaler Getrieberuck [Nm/s]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeparameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxGearJerk(int axIdx, double* maxJerk);

      //! \brief Holen des Uebersetzungsfaktors Antrieb nach Abtrieb
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] factor       Faktor Antrieb nach Abtrieb
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeparameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getRoreFactor(int axIdx, double* factor);

      //! \brief Holen der Maximalen �berschleifdistanz \$APO_DIS_PTP
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] maxDis     Maximale �berschleifdistanz
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeparameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getMaxApproxDis(int axIdx, double* maxDis);

      //! \brief Holen des negativen Softwareendschalers (\$SOFTN_END[]) einer Achse
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] limit        Softwareendschalter [�] bzw. [mm]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeparameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getJointLimitMin(int axIdx, double* limit);

      //! \brief Holen des positiven Softwareendschalers ($SOFTP_END[]) einer Achse
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  axIdx        Index der Achse.
      //! \param[out] limit        Softwareendschalter [�] bzw. [mm]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  �bergabeparameter ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getJointLimitMax(int axIdx, double* limit);

      //! \brief Holen des Beschleunigungsreduktionsfaktors \$RED_ACC_DYN
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] factor       Beschleunigungsreduktionsfaktor
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getRedAccDyn(double* factor);

      //! \brief Holen der Anzahl an Zusatzachsen (\$EX_AX_NUM)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] exAxNum      Anzahl Zusatzachsen
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getExAxNum(int* exAxNum);

      //! \brief Holen der Anzahl an Roboterachsen (\$TRAFO_AXIS)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] robAxNum      Anzahl Roboterachsen
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getRobAxNum(int* robAxNum);

      //! \brief Holen des Defaultfilters fuer das PTP-Fahren (\$DEF_FLT_PTP)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] filter       Filterlaenge [ms]
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getDefFltPtp(double* filter);

      //! \brief Holen des internen Roboterkoordinatensystem bez�glich des
      //!        Roboterfu�es (\$TIRORO).
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] TIroRo       Frame IRO bezueglich Frame ROBROOT
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getTIroRo(ml_CFrame* TIroRo);

      //! \brief Holen des Flansch bezueglich dem Handwurzelpunkt ($TFLWP)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] TFlWp        Frame Flansch bezueglich Frame Handwurzelpunkt
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getTFlWp(ml_CFrame* TFlWp);

      //! \brief Holen des Roboterfuss bezueglich der Welt (\$ROBROOT)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] TRoWo       Frame ROBROOT bez�glich Frame WORLD
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getTRoWo(ml_CFrame* TRoWo);

      //! \brief Holen des Modus der Beschleunigungsanpassung
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] adapAcc   Wert 1 entspricht \$ADAP_ACC = \#NONE,\n
      //!                       Wert 2 entspricht \$ADAP_ACC = \#STEP1, \n
      //!                       Wert 3 entspricht \$ADAP_ACC = \#STEP2
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getAdapAcc(int* adapAcc);

      //! \brief Holen der Defaultlastdaten am Flansch
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] Mass         Masse am Flansch
      //! \param[out] CenterOfMass Lastschwerpunkt bzgl. Flansch
      //! \param[out] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                          (Ixx, Iyy, Izz)
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL getDefaultLoad(double &Mass, ml_CFrame &CenterOfMass,
            ml_CVector3 &Inertia);

      //! \brief Holen der Defaultlastdaten auf Achse 3
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] Mass         Masse auf Achse 3
      //! \param[out] CenterOfMass Lastschwerpunkt bzgl. Flansch
      //! \param[out] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                          (Ixx, Iyy, Izz)
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL getDefaultLoadA3(double &Mass, ml_CFrame &CenterOfMass, ml_CVector3 &Inertia);

      //! \brief Auslesen des Bitfelds an- und abgekoppelter Zusatzachsen
      //!        (\$ASYNC_EX_AX_DECOUPLE)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  pAsyncExAxDecouple  Bitfeld:
      //!                                 - Bit == 0: Achse angekoppelt
      //!                                 - Bit == 1: Achse abgekoppelt
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getAsyncExAxDecouple(int *pAsyncExAxDecouple);

      //! \brief Auslesen des Bitfelds (a-)synchroner Zusatzachsen
      //!        (\$ASYNC_AXIS)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  pAsyncAxis   Bitfeld:
      //!                          - Bit == 0: Achse synchron
      //!                          - Bit == 1: Achse asynchron
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  Ergebniszeiger ung�ltig
      //! \retval     ROBOT_OK              Kein Fehler
      ROBOT_RETVAL getAsyncAxis(int *pAsyncAxis);

      //! \brief Aufruf der Vorw�rtstransformation
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen und die Transformation �ber den Aufruf von configureTrafo()
      //! konfiguriert worden sein.
      //!
      //! \param[in]  AxisInput   Achswinkel in Grad bzw. mm (analog E6Axis)
      //! \param[out] CartOutput  Kartesische Position (analog E6Pos)
      //! \param[in]  Tool        Zeiger auf Toolframe (optional)
      //! \param[in]  Base        Zeiger auf Baseframe (optional)
      //! \param[in]  IpoMode     Zeiger auf Interpolationsmodus (optional)
      //! \param[in]  TrafoMode   Transformationsmodus (PTP, CP, OriJoint, singul�rer Punkt)
      //!
      //! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED Trafo nicht konfiguriert
      //! \retval ROBOT_INPUTS_INVALID Inputdaten (aktive Achsen) unvollst�ndig
      //! \retval ROBOT_ERROR Transformation konnte nicht durchgef�hrt werden
      //! \retval ROBOT_OK    Kein Fehler
      ROBOT_RETVAL Forward(const CAxisPosition& AxisInput, CCartesianPosition& CartOutput,
                           const ml_CFrame *Tool = 0, const ml_CFrame *Base = 0, const EIpoMode *IpoMode = 0,
                           const ETrafoMode TrafoMode = TRAFO_CP_SPKT);

      //! \brief Aufruf der R�ckw�rtstransformation
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen und die Transformation �ber den Aufruf von configureTrafo()
      //! konfiguriert worden sein.
      //!
      //! \param[in]  CartInput   Kartesische Position (analog E6Pos)
      //!                         Bei ung�tligem Status oder Frame erfolgt keine Trafo!
      //!                         Der Turn wird derzeit ignoriert (implizit Turn 0)
      //! \param[in]  AxisInput   Optionaler Vorg�nger-Achswinkel in Grad bzw. mm (analog E6Axis)
      //! \param[out] AxisOutput  Achswinkel in Grad bzw. mm (analog E6Axis)
      //! \param[in]  Tool        Zeiger auf Toolframe (optional)
      //! \param[in]  Base        Zeiger auf Baseframe (optional)
      //! \param[in]  IpoMode     Zeiger auf Interpolationsmodus (optional)
      //! \param[in]  TrafoMode   Transformationsmodus (PTP, CP, OriJoint, singul�rer Punkt)
      //!
      //! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED Trafo nicht konfiguriert
      //! \retval ROBOT_INPUTS_INVALID Inputdaten (Frame/Status) unvollst�ndig
      //! \retval ROBOT_ERROR Transformation konnte nicht durchgef�hrt werden
      //! \retval ROBOT_OK    Kein Fehler
      ROBOT_RETVAL Backward(const CCartesianPosition &CartInput,
                                  CAxisPosition      &AxisOutput,
                            const CAxisPosition      &AxisInput = CAxisPosition(),
                            const ml_CFrame *Tool = 0, const ml_CFrame *Base = 0,
                            const EIpoMode *IpoMode = 0, const ETrafoMode TrafoMode = TRAFO_CP_SPKT);

      //! \brief Aufruf der absolutgenauen Vorw�rtstransformation
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! (inklusive RobotInfo.xml und X-Pid) geladen und die Transformation �ber
      //! den Aufruf von configureTrafo() konfiguriert worden sein.
      //!
      //! \param[in]  AxisInput   Achswinkel in Grad bzw. mm (analog E6Axis)
      //! \param[out] CartOutput  Kartesische Position (analog E6Pos)
      //! \param[in]  Tool        Zeiger auf Toolframe (optional)
      //! \param[in]  Base        Zeiger auf Baseframe (optional)
      //! \param[in]  IpoMode     Zeiger auf Interpolationsmodus (optional)
      //! \param[in]  TrafoMode   Transformationsmodus (PTP, CP, OriJoint, singul�rer Punkt)
      //!
      //! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED absolutgenaue Trafo nicht
      //!                     konfiguriert
      //! \retval ROBOT_INPUTS_INVALID Inputdaten (aktive Achsen) unvollst�ndig
      //! \retval ROBOT_ERROR Transformation konnte nicht durchgef�hrt werden
      //! \retval ROBOT_OK    Kein Fehler
      ROBOT_RETVAL ForwardHA(const CAxisPosition& AxisInput, CCartesianPosition& CartOutput,
                             const ml_CFrame *Tool = 0, const ml_CFrame *Base = 0, const EIpoMode *IpoMode = 0,
                             const ETrafoMode TrafoMode = TRAFO_CP_SPKT);

      //! \brief Aufruf der absolutgenauen R�ckw�rtstransformation
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! (inklusive RobotInfo.xml und X-Pid) geladen und die Transformation �ber
      //! den Aufruf von configureTrafo() konfiguriert worden sein.
      //!
      //! \param[in]  CartInput   Kartesische Position (analog E6Pos)
      //!                         Bei ung�tligem Status oder Frame erfolgt keine Trafo!
      //!                         Der Turn wird derzeit ignoriert (implizit Turn 0)
      //! \param[in]  AxisInput   Optionaler Vorg�nger-Achswinkel in Grad bzw. mm (analog E6Axis)
      //! \param[out] AxisOutput  Achswinkel in Grad bzw. mm (analog E6Axis)
      //! \param[in]  Tool        Zeiger auf Toolframe (optional)
      //! \param[in]  Base        Zeiger auf Baseframe (optional)
      //! \param[in]  IpoMode     Zeiger auf Interpolationsmodus (optional)
      //! \param[in]  TrafoMode   Transformationsmodus (PTP, CP, OriJoint, singul�rer Punkt)
      //!
      //! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED absolutgenaue Trafo nicht
      //!                     konfiguriert
      //! \retval ROBOT_INPUTS_INVALID Inputdaten (Frame/Status) unvollst�ndig
      //! \retval ROBOT_ERROR Transformation konnte nicht durchgef�hrt werden
      //! \retval ROBOT_OK    Kein Fehler
      ROBOT_RETVAL BackwardHA(const CCartesianPosition &CartInput,
                                    CAxisPosition      &AxisOutput,
                              const CAxisPosition      &AxisInput = CAxisPosition(),
                              const ml_CFrame *Tool = 0, const ml_CFrame *Base = 0,
                              const EIpoMode *IpoMode = 0, const ETrafoMode TrafoMode = TRAFO_CP_SPKT);

      //! \brief Umrechnung einer Achsposition bez�glich des k�rzesten Wegs
      //!        zu einer Vorg�ngerposition.
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! erfolgreich geladen worden sein.
      //!
      //! \param[in] CurrAxisPos  Aktuelle Achswinkel [Grad|mm]
      //! \param[in] LastAxisPos  Letzte Achswinkel  [Grad|mm]
      //! \param[in] NewAxisPos   Neue Achswinkel  [Grad|mm] berechnet aus
      //!                         CurrAxisPos unter Ber�cksichtigung des
      //!                         k�rzesten Weges zu LastAxisPos
      //!
      //! \retval ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval ROBOT_INPUTS_INVALID Eingangsdaten nicht vollst�ndig belegt
      //! \retval ROBOT_OK             Umrechnung erfolgreich
      ROBOT_RETVAL ShortestPath(const CAxisPosition& CurrAxisPos,
                                const CAxisPosition& LastAxisPos,
                                CAxisPosition& NewAxisPos);

      //! \brief Softwareendschalter �berpr�fen
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! erfolgreich geladen worden sein.
      //!
      //! \param[in]  AxisPos  Achswinkel   [mm|Deg]
      //!
      //! \retval     ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID Inputdaten (AxisPos) unvollst�ndig belegt
      //! \retval     ROBOT_ERROR          mindestens ein Softwareendschalter verletzt
      //! \retval     ROBOT_OK             alle Softwareendschalter erf�llt
      ROBOT_RETVAL CheckAxisLimits(const CAxisPosition &AxisPos);

      //! \brief Motorwinkel in Achswinkel umrechnen
      //!
      //! \attention Als Parameter werden Arrays der L�nge MAX_ACHS (12) erwartet
      //!
      //! \param[in]  MotorPos  Motorwinkeln in [Deg]
      //! \param[out] AxisPos   Achswinkel in [mm] oder [Deg]
      //!
      //! \retval     ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID Inputdaten (MotorPos) unvollst�ndig belegt
      //! \retval     ROBOT_OK             Kein Fehler
      ROBOT_RETVAL transferMotorToJointAngles(const CMotorPosition& MotorPos, CAxisPosition& AxisPos);

      //! \brief Achswinkel in Motorwinkel umrechnen
      //!
      //! \attention Als Parameter werden Arrays der L�nge MAX_ACHS (12) erwartet
      //!
      //! \param[in]  AxisPos   Achswinkel  [mm] oder [Deg]
      //! \param[out] MotorPos  Motorwinkel [Deg]
      //!
      //! \retval     ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID Inputdaten (AxisPos) unvollst�ndig belegt
      //! \retval     ROBOT_OK             Kein Fehler
      ROBOT_RETVAL transferJointToMotorAngles(const CAxisPosition& AxisPos, CMotorPosition& MotorPos);

      //! \brief Berechnung des (normierten) Abstands zu den Singularit�ten
      //!        (\$SINGUL_DIST[])
      //!
      //! Die Funktion berechnet aus den Achswinkeln den normierten Abstand
      //! zu den jeweiligen Singularitaeten, die mehrdeutige Achsstellungen
      //! erm�glichen.
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen und die Transformation �ber den Aufruf von configureTrafo()
      //! konfiguriert worden sein.
      //!
      //! \param[in]  AxisPos     Refernz einer Achsposition (projektierte
      //!                         Roboterachsen m�ssen dabei g�ltig sein)
      //! \param[out] singDist    Vektor mit 3 Abst�nden
      //!
      //! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED Trafo nicht konfiguriert
      //! \retval ROBOT_INPUTS_INVALID  Inputdaten (AxisPos) unvollst�ndig belegt
      //! \retval ROBOT_OK              Kein Fehler
      ROBOT_RETVAL SingulDist(ml_CVector3& singDist, const CAxisPosition& AxisPos);

      //! \brief Berechnung der abtriebsseitigen Motor- und Getriebmomente �ber
      //!        das inverse Dynamikmodell (Newton-Euler-Algorithmus).
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]      q           geometrische Achsposition [deg] oder [mm].
      //! \param[in]      qd          geometrische Achsgeschwindigkeiten [deg/s] oder [mm/s].
      //! \param[in]      qdd         geometrische Achsbeschleunigungen [deg/s^2] oder [mm/s^2].
      //! \param[in]      CalcMode    Berechnungsmodus gem�� HFP_CALC_MODE.
      //! \param[out]     gearTorque  Getriebemomente um die Achsen am Abtrieb [Nm].
      //! \param[out]     motorTorque Motormomente um die Achsen am Abtrieb [Nm].
      //!
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED Dynamikmodell nicht konfiguriert
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL calcInverseDynamics(const double q[MAX_ACHS], const double qd[MAX_ACHS], const double qdd[MAX_ACHS],
                                       double gearTorque[MAX_ACHS], double motorTorque[MAX_ACHS],
                                       int CalcMode = HFP_CALC_MOM | HFP_AD_FACTORS);

      //! \brief Berechnung der Inversdynamik in parameterlinearer Form f�r die
      //!        Lastdatenidentifikation.
      //!        Es gilt:
      /*! \f[
              \tau = Rest + Matrix * P, P = [m, m*[CM], J].
          \f] */
      //!        Dabei m*[CM] Schwerpunktvektor multipliziert mit der Masse und
      //!        J auf den Gelenkpunkt bezogen - Verschiebung um CM liefert
      //!        die Tr�gheit im Schwerpunktsystem.
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann muessen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]      q           geometrische Achsposition [deg] oder [mm].
      //! \param[in]      qd          geometrische Achsgeschwindigkeiten [deg/s] oder [mm/s].
      //! \param[in]      qdd         geometrische Achsbeschleunigungen [deg/s^2] oder [mm/s^2].
      //! \param[in]      AxisToIdentify  Index der Achse f�r die die Starrk�rperdaten linearisiert werden sollen.
      //!
      //! \param[out]     Rest        Anteil der nicht zu identifizierenden Achsen
      //! \param[out]     Matrix      12x10-Matrix der Linearisierung f�r AxisToIdentify!
      //!
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED Dynamikmodell nicht konfiguriert
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL calcInverseDynamicsParLin(const double q[MAX_ACHS], const double qd[MAX_ACHS], const double qdd[MAX_ACHS],
            double *Matrix, double *Rest, int AxisToIdentify);

      //! \brief Berechnung der direkten Dynamik (reines Starrk�rpermodell abtriebsseitig).
      //!
      //! Ausgegeben werden die Komponenten M, C und (G + F_ext) aus
      /*! \f[
              \tau  = M(q) \ddot q + C(q, \dot q) + G(q) + F_{ext}.
          \f] */
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]      q           geometrische Achsposition [deg] oder [mm].
      //! \param[in]      qd          geometrische Achsgeschwindigkeiten [deg/s] oder [mm/s].
      //! \param[in]      CalcMode    Auswahl der zu berechnenden Komponenten der Dynamikgleichung
      //! \param[out]     MassMatrix  Massentr�gheitsmatrix als Vektor der L�nge (MAX_ACHS^2)!!
      //!                             (wird spaltenweise belegt)
      //! \param[out]     Coriolis    Vektor der Corioliskr�fte/momenten [N/Nm]
      //! \param[out]     Gravity     Vektor der statischen Anteile Gravitation + evtl. GWA [N/Nm]
      //!
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED Dynamikmodell nicht konfiguriert
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL calcDirectDynamics(const double q[MAX_ACHS], const double qd[MAX_ACHS],
                                      double *MassMatrix, double *Coriolis, double *Gravity,
                                      int CalcMode =  HFP_CALC_STATIC | HFP_CALC_COR | HFP_CALC_MASS);


      //! \brief Berechnung der kinetischen Energie in den Achsen
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]      q           geometrische Achsposition [deg] oder [mm].
      //! \param[in]      qd          geometrische Achsgeschwindigkeiten [deg/s] oder [mm/s].
      //! \param[out]     energy      Energie der Achsen [J]
      //!
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED Dynamikmodell nicht konfiguriert
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL calcKineticEnergy(const double *q, const double *qd, double *energy);

      //! \brief Berechnung des Moments auf die Achsen, das durch einen
      //!        Gewichtsausgleich induziert wird.
      //!
      //! \attention
      //! \li Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //!     geladen worden sein.
      //! \li Im Dynamikmodell kann auf jede Achse ein Gewichtsausgleich angewendet
      //!     werden.
      //!
      //! \param[in]      q           geometrische Achsposition [deg] oder [mm].
      //! \param[out]     cbsTorque   induziertes Moment auf den Achsen [Nm]
      //!
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED Dynamikmodell nicht konfiguriert
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL calcCBS(const double *q, double *cbsTorque);

      //! \name   Meldungswesen
      //! @{

      //! \brief Liefert die letzte anstehende (Fehler)Meldung. Kommt eine beliebige
      //!        Methode dieser (und auch abgeleiteter) Klassen mit Fehler (wie z.B.
      //!        ROBOT_ERROR) zur�ck, so kann �ber getLatestMessage ggf. die
      //!        zugeh�rige Fehlermeldung (welche in der KRC anst�nde) ausgelesen
      //!        werden.
      //!
      //! \param[in]  LatestMsg Aktuellste Fehlermeldung
      //!
      //! \retval ROBOT_OK     Fehlermeldung gefunden und in LatestMsg eingetragen
      //! \retval ROBOT_ERROR  Aktuell steht keine Meldung an - LatestMsg ung�ltig
      ROBOT_RETVAL getLatestMessage(CKrcMessage &LatestMsg);

      //! \brief Liefert die �ber den 1-basierten Meldungsindex spezifizierte Meldung.
      //!
      //! \param[in]  MsgIdx   Meldungsindex
      //!
      //! \param[out] Msg      Fehlermeldung
      //!
      //! \retval ROBOT_OK     Fehlermeldung gefunden und in Msg eingetragen
      //! \retval ROBOT_ERROR  Der Meldungsindex liegt nicht in der Liste
      ROBOT_RETVAL getMessage(unsigned int MsgIdx, CKrcMessage &Msg);

      //! \brief Diese Methode liefert eine komplette Kopie der intern gepflegten
      //!        Meldungsliste. Die aktuellste Meldung steht am Begin der Liste,
      //!        die �lteste Meldung am Ende. Per Default werden maximal die letzen
      //!        40 Meldungen gepflegt. Ist die Liste voll, so �berschreibt jede
      //!        neue Meldung automatisch die �lteste Meldung in der Liste.
      //!
      //! \param[in]  MsgList   Liste der aktuell verwalteten  Fehlermeldungen
      //! \retval ROBOT_OK     Nicht leere Fehlerliste nach MsgList kopiert
      //! \retval ROBOT_ERROR  Interne Fehlerliste ist leer (MsgList ebenfalls)
      ROBOT_RETVAL getAllMessages(std::list<CKrcMessage> &MsgList);

      //! \brief Alle Meldungen der internen Meldungsliste abnullen.
      //! \retval ROBOT_OK     Interne Liste erfolgreich abgenullt
      //! \retval ROBOT_ERROR  Interne Liste war schon leer
      ROBOT_RETVAL clearAllMessages();

      //! \brief �ndert die Gr��e des internen Meldungspuffers (maximal 1000
      //!        Meldungen k�nnen vorgehalten werden)
      //!
      //! \param[in]  N  neue L�nge des Meldungspuffers  (zwischen 1 und 1000)
      //!
      //! \retval ROBOT_OK               Pufferl�nge erfolgreich gesetzt
      //! \retval ROBOT_INPUTS_INVALID   unzul�ssige Pufferl�nge
      ROBOT_RETVAL setLengthOfMsgQueue(int N);

      //! \brief Berechnet zur gegebenen Gelenkstellung q die Jacobimatrix J(q) im entsprechenden Koordinatensystem. 
      //! \brief Dabei ist q in KernelDLL-Notation angegeben (Grad, Achsreihenfolge ROB_ACHS 1...6, EXT_ACHS 1...6).
      //! \brief Die Matrix ist wie folgt aufgebaut:<br>
      //! \brief                            ROB_ACHS 1  ...  ROB_ACHS 6      EXT_ACHS 1 ... EXT_ACHS 6
      //! \brief   Translations�nderung x        
      //! \brief   Translations�nderung y  
      //! \brief   Translations�nderung z 
      //! \brief   Rotations�nderung um x
      //! \brief   Rotations�nderung um y
      //! \brief   Rotations�nderung um z
      //! \brief
      //! \brief Die Achsreihenfolge entspricht der KernelDLL-Notation (MAX_ROB_ACHS Roboterachsen + MAX_EXT_ACHS Zusatzachsen), sofern nicht der 
      //! \brief Parameter "calculateKinematicChainJacobi == true" gesetzt wird.
      //!
      //! \param[in] q[MAX_ACHS] Achsstellung des Roboters (in Grad), maximal MAX_ACHS Achsen
      //! \param[in] tool Toolframe mit Translation in Millimetern
      //! \param[out] J[6xMAX_ACHS] Jacobimatrix Einheiten [m/s bzw. rad/s]
      //! \param[in] toolToWorldJacobi Optional: Parameter zur Berechnung der Jacobimatrix im <b>Tool</b> Koordinatensystem (default ist: <b>Basissystem der dynamischen Kette</b> // false)
      //! \param[in] calculateKinematicChainJacobi Optional: Falls true entspricht die Achsreihenfolge der in Chaindata.xml angegebenen (default ist: false)
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateJacobian(const double (&q)[MAX_ACHS], ml_CFrame &tool, double (&J)[6][MAX_ACHS], bool toolToBaseJacobi = false, bool calculateKinematicChainJacobi = false);

      //! \brief Berechnet die Jacobimatrix (Details siehe oben). Einziger Unterschied zur anderen calculateJacobian Methode: Es muss kein Toolframe �bergeben werden,
      //! \brief das globale Toolframe wird verwendet.
      ROBOT_RETVAL calculateJacobian(const double (&q)[MAX_ACHS], double (&J)[6][MAX_ACHS], bool toolToBaseJacobi = false, bool calculateKinematicChainJacobi = false);


      //! \brief Berechnet Rotationen und Translationen der einzelnen Achsen der Roboterkette. Die Reihenfolge der
      //! \brief Matrizen bzw. Vektoren entspricht dabei der Reihenfolge in der Kette und nicht dem Achsindex.
      //!
      //! \param[in]  q[MAX_ACHS] Achsstellung des Roboters (in Grad/mm), maximal MAX_ACHS Achsen
      //! \param[out] R[MAX_ACHS][3][3] Array von 3x3-Rotationsmatrizen f�r alle Achsen der Kette
      //! \param[out] s[MAX_ACHS][3] Array von 3x1-Translationsvektoren f�r alle Achsen der Kette
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateTransformationMatrix(const double (&q)[MAX_ACHS], double (&R)[MAX_ACHS][3][3], double (&s)[MAX_ACHS][3]);

      //! \brief Berechnet Frames von Fusspunkt der dynamischen Kette zu jeder Achse bzw. bei letzter Achse bis zum Tool. 
      //! \brief die Funktion ber�cksichtigt die Achsreihung der kinematischen Kette aus der
      //! \brief ChainData.xml.
      //!
      //! \param[in] q[MAX_ACHS] Achsstellung des Roboters (in Grad), maximal MAX_ACHS Achsen
      //! \param[in] tool Toolframe erlaubt das Berechnen der Jacobimatrix f�r beliebige Tools ohne Seiteneffekte
      //!                 Einheit des Translationsteils sind [m]
      //! \param[out] frameArray[MAX_ACHS] Array von ml_CFrames von Base zu jeder Achse bzw. f�r letzte Achse zum Tool
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateFrameMatrix(const double (&q)[MAX_ACHS], const ml_CFrame &tool, ml_CFrame (&frameArray)[MAX_ACHS]);
      

      //! \brief Berechnet Frames vom Tool zu jeder Achse, wobei die Funktion die Achsreihung der kinematischen Kette
      //! \brief aus der ChainData.xml ber�cksichtigt.
      //!
      //! \param[in] q[MAX_ACHS] Achsstellung des Roboters (in Grad), maximal MAX_ACHS Achsen
      //! \param[in] tool Toolframe erlaubt das Berechnen der Jacobimatrix f�r beliebige Tools ohne Seiteneffekte
      //!                 Einheit des Translationsteils sind [m]
      //! \param[out] frameArray[MAX_ACHS] Array von ml_CFrames von Tool zu jeder Achse
      //! \retval ROBOT_OK Alles OK
      //! \retval ROBOT_ERROR Nicht alles ok
      ROBOT_RETVAL calculateFrameMatrixTool(const double (&q)[MAX_ACHS], const ml_CFrame &tool, ml_CFrame (&frameArray)[MAX_ACHS]);
    
      //! @}
};


//! \brief   Kapselung eines Robotervollobjekts (Lese- und Schreibzugriff)
//!          nach au�en.
//!
//! Diese Klasse umfasst alle grundlegenden Methoden zum Anlegen und Verwalten
//! von eigenst�ndigen Roboterobjekten:
//! \li Diese Klasse ist Multiinstanzierbar (beliebig viele Objekte denkbar)
//! \li Bringt einen EIGENEN Madalader zwecks Konfiguration des Roboter mit
//! \li Unterst�tz alle Schnittstellen der CRobotBase Klasse
//! \li Kann zugrunde liegende Objekt modifizeren (z.B. Tool f�r Trafo setzen)
//! \li Kann f�r Trafo- und Dynamikauswertungen verwendet werden
//! \li Ist bei der Generierung von Splines erforderlicher Inputparameter
//!     des CSplineBase Konstruktors
class _DLL_ CRobot : public CRobotBase
{
   protected:

      //! \brief Sind g�ltige Maschinendaten vorhanden
      bool bMadaValid;

      //! \brief Wurde die Trafo erfolgreich konfiguriert
      bool bTrafoConfigured;

      //! \brief Wurde das Dynamikmodell erfolgreich konfiguriert
      bool bDynamicModelConfigured;

   private:
      //! \brief Copykonstruktor und Wertzuweisung sind verboten!
      //! @{
      CRobot(const CRobot& Dummy);
      CRobot& operator=(const CRobot& Dummy);
      //! @}

   public:

      //! \brief Einzig zul�ssiger CRobot Konstruktor zur Erzeugung eigenst�ndiger
      //!        Roboterobjekte
      CRobot();

      //! \brief Destruktor
      virtual ~CRobot();

      //! \brief Einlesen von Maschinendaten.
      //!
      //! \attention
      //! Im Fehlerfall wird immer eine MadaInternalErrorExc Exception geworfen!
      //!
      //! \param[in]  sR1          String zum R1-Verzeichnis in dem sich \$robcor.dat
      //!                          und \$machine.dat befinden
      //! \param[in]  sConfig      Optionaler String zum Config Verzeichnis
      //! \param[in]  sPathToRobotInfo  Optionaler String zum Verzeichnis, das die
      //!                               RobotInfo.xml und das precrobXXX.xml enth�lt
      //! \param[in]  sMotor       Optionaler String zu einem zweiten Config-Verzeichnis,
      //!                          das beispielsweise das Motor-Verzeichnis mit den
      //!                          Motor-XML-Files enth�lt.
      //!                          Ist dieser angegeben, so wird er beim Laden der
      //!                          Maschinendaten auch ber�cksichtigt. Damit k�nnen
      //!                          insbesondere auch Maschinendaten von CD gelesen
      //!                          werden. Ohne diesen Pfad sucht loadMada() die
      //!                          Motor-XML-Files wie auf der Steuerung zuerst unter
      //!                          Config\\User\\Common\\Motor und falls dort nichts
      //!                          gefunden wird unter Config\\System\\Common\\Motor.
      void loadMADA(char *sR1 = 0, char *sConfig = 0, char *sPathToRobotInfo = 0, char *sMotor = 0);

      //! \brief   Pr�fen der Maschinendaten auf Gueltigkeit
      //!
      //! \retval true   Maschinendaten g�ltig
      //! \retval false  Maschinendaten ung�ltig
      virtual bool isMadaValid() const;

      //! \brief Pr�fen, ob die Trafo verf�gbar ist.
      //!
      //! \retval true   Trafo verf�gbar
      //! \retval false  Trafo nicht verf�gbar
      virtual bool isTrafoConfigured() const;

      //! \brief Pr�fen, ob das Dynamik Modell konfiguriert ist
      //!
      //! \retval true   Dynamik Modell verf�gbar
      //! \retval false  Dynamik Modell nicht verf�gbar
      virtual bool isDynamicModelConfigured() const;

      //! \brief   Interpolationstakt in [sec] setzen.
      //!
      //! \param[in]  TIpo      zu setzender Interpolationstakt in [sec]
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setInterpolationCycle(double TIpo);

      //! \brief   \$SPTP_EXAX_PARA schreiben
      //!
      //! \param[in]  ExAxPara  Parametrisierungswunsch
      //!
      //! \retval     ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK            Kein Fehler
      ROBOT_RETVAL setSptpExAxPara(const ESplineParaVariant (&ExAxPara)[6]);

      //! \brief   \$TOOL setzen
      //!
      //! \param[in]  Tool      zu setzendes Tool-Frame
      //!
      //! \retval     ROBOT_TRANSFORMATION_NOT_CONFIGURED  Selbsterkl�rend.
      //! \retval     ROBOT_ERROR   Zuweisung an \$TOOL fehlgeschlagen
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setTool(const ml_CFrame& Tool);

      //! \brief   Werkzeugsto�richtung setzen (nur bei Spline relevant)
      //!
      //! \param[in] ToolDirection      zu setzende Sto�richtung
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setToolDirection(const EToolDirection& ToolDirection);

      //! \brief   \$BASE setzen
      //!
      //! \param[in]  Base      zu setzendes Base-Frame
      //!
      //! \retval     ROBOT_TRANSFORMATION_NOT_CONFIGURED  Selbsterkl�rend.
      //! \retval     ROBOT_ERROR   Zuweisung an \$BASE fehlgeschlagen
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setBase(const ml_CFrame& Base);

      //! \brief      $ROT_SYS setzen
      //!
      //! Folgende Kombinationen sind gueltig (vgl. rotsys.c):
      //!    \li IpoMode = BASE   und   RotSys = AS_TRA
      //!    \li IpoMode = BASE   und   RotSys = TCP
      //!    \li IpoMode = TCP    und   RotSys = AS_TRA
      //!    \li IpoMode = TCP    und   RotSys = BASE
      //!
      //! \param[in]  RotSys        zu setzendes RotSys
      //!
      //! \retval     ROBOT_ERROR   uebergebenes RotSys ung�ltig
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setRotSys(const ERotSys RotSys);

      //! \brief   Ipo-Mode setzen
      //!
      //! \param[in] IpoMode      zu setzender IpoMode
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig.
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setIpoMode(const EIpoMode IpoMode);

      //! \brief Konfiguration der Transformation aus den Maschinendaten
      //!
      //! \attention
      //! Die notwendigen Maschinendaten muessen durch den Maschinendatenlader
      //! vorab ermittelt und bereitgestellt werden. Durch diesen Aufruf wird nur
      //! noch die Transformation konfiguriert.
      //!
      //! \retval ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED gem. Madas keine Trafo gew�nscht
      //! \retval ROBOT_ERROR         Transformation konnte nicht initialisiert werden
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL configureTrafo();

      //! \brief Konfiguration des Dynamikmodells.
      //!
      //! \attention
      //! Die notwendigen Maschinendaten muessen durch den Maschinendatenlader
      //! vorab ermittelt und bereitgestellt werden. Durch diesen Aufruf wird nur
      //! noch das Dynamikmodell konfiguriert.
      //!
      //! \param[out] Error       Fehlercode (identisch mit HFPFillReturnCode):
      //!                         \li  0: Dyndat-Strukturen erfolgreich gef�llt
      //!                         \li  2: Nicht implementierte Kinematik
      //!                         \li  9: Unbekannter GWA-Typ
      //!                         \li 10: Abweichung zwischen \$DYN_DAT[] und den Trafo-Daten
      //!                         \li 11: Momentenkennlinie ung�ltig
      //!                         \li 12: Dynamikmodell nicht aktiv
      //!
      //! \retval ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED gem. Madas keine Modell vorhanden
      //! \retval ROBOT_ERROR         Modell konnte nicht initialisiert werden.
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL configureDynamicModel(int* Error = 0);


      //! \brief Holen der Lastdaten am Flansch (\$LOAD)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] Mass         Masse am Flansch
      //! \param[out] CenterOfMass Lastschwerpunkt bzgl. Flansch
      //! \param[out] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                          (Ixx, Iyy, Izz)
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig
      //! \retval     ROBOT_OK           Kein Fehler
      ROBOT_RETVAL getLoad(double &Mass, ml_CFrame &CenterOfMass, ml_CVector3 &Inertia);

      //! \brief Holen der Zusatzlast Achse 1 (\$LOAD_A1)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] Mass         Masse am Flansch
      //! \param[out] CenterOfMass Lastschwerpunkt bzgl. Flansch
      //! \param[out] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                          (Ixx, Iyy, Izz)
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig
      //! \retval     ROBOT_OK           Kein Fehler
      ROBOT_RETVAL getLoadA1(double &Mass, ml_CFrame &CenterOfMass, ml_CVector3 &Inertia);

      //! \brief Holen der Zusatzlast Achse 2 (\$LOAD_A2)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] Mass         Masse am Flansch
      //! \param[out] CenterOfMass Lastschwerpunkt bzgl. Flansch
      //! \param[out] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                          (Ixx, Iyy, Izz)
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig
      //! \retval     ROBOT_OK           Kein Fehler
      ROBOT_RETVAL getLoadA2(double &Mass, ml_CFrame &CenterOfMass, ml_CVector3 &Inertia);

      //! \brief Holen der Zusatzlast Achse 3 (\$LOAD_A3)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[out] Mass         Masse am Flansch
      //! \param[out] CenterOfMass Lastschwerpunkt bzgl. Flansch
      //! \param[out] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                          (Ixx, Iyy, Izz)
      //!
      //! \retval     ROBOT_MADA_INVALID Maschinendaten ung�ltig
      //! \retval     ROBOT_OK           Kein Fehler
      ROBOT_RETVAL getLoadA3(double &Mass, ml_CFrame &CenterOfMass, ml_CVector3 &Inertia);

      //! \brief Setzen der Lastdaten am Flansch
      //!
      //! \param[in] Mass         Masse am Flansch [kg]
      //! \param[in] CenterOfMass Lastschwerpunkt bzgl. Flansch [mm]
      //! \param[in] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                         (Ixx, Iyy, Izz) [kgm^2]
      //!
      //! \param[out] Error       Fehlercode (identisch mit HFPFillReturnCode):
      //!                         \li  0: Dyndat-Strukturen erfolgreich gef�llt
      //!                         \li  2: Nicht implementierte Kinematik
      //!                         \li  9: Unbekannter GWA-Typ
      //!                         \li 10: Abweichung zwischen \$DYN_DAT[] und den Trafo-Daten
      //!                         \li 11: Momentenkennlinie ung�ltig
      //!                         \li 12: Dynamikmodell nicht aktiv
      //!
      //! \retval ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED gem. Madas keine Modell vorhanden
      //! \retval ROBOT_ERROR         Modell konnte nicht initialisiert werden.
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL setLoad(const double Mass, const ml_CFrame &CenterOfMass, const ml_CVector3 &Inertia, int *Error = 0);

      //! \brief Setzen der Zusatzlastdaten auf Achse 1
      //!
      //! \param[in] Mass         Masse auf Achse 1 [kg]
      //! \param[in] CenterOfMass Lastschwerpunkt bzgl. ROBROOT [mm]
      //! \param[in] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                         (Ixx, Iyy, Izz) [kgm^2]
      //!
      //! \param[out] Error       Fehlercode (identisch mit HFPFillReturnCode):
      //!                         \li  0: Dyndat-Strukturen erfolgreich gef�llt
      //!                         \li  2: Nicht implementierte Kinematik
      //!                         \li  9: Unbekannter GWA-Typ
      //!                         \li 10: Abweichung zwischen \$DYN_DAT[] und den Trafo-Daten
      //!                         \li 11: Momentenkennlinie ung�ltig
      //!                         \li 12: Dynamikmodell nicht aktiv
      //!
      //! \retval ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED gem. Madas keine Modell vorhanden
      //! \retval ROBOT_ERROR         Modell konnte nicht initialisiert werden.
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL setLoadA1(const double Mass, const ml_CFrame &CenterOfMass, const ml_CVector3 &Inertia, int *Error = 0);

      //! \brief Setzen der Zusatzlastdaten auf Achse 2
      //!
      //! \param[in] Mass         Masse auf Achse 2 [kg]
      //! \param[in] CenterOfMass Lastschwerpunkt bzgl. ROBROOT [mm]
      //! \param[in] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                         (Ixx, Iyy, Izz) [kgm^2]
      //!
      //! \param[out] Error       Fehlercode (identisch mit HFPFillReturnCode):
      //!                         \li  0: Dyndat-Strukturen erfolgreich gef�llt
      //!                         \li  2: Nicht implementierte Kinematik
      //!                         \li  9: Unbekannter GWA-Typ
      //!                         \li 10: Abweichung zwischen \$DYN_DAT[] und den Trafo-Daten
      //!                         \li 11: Momentenkennlinie ung�ltig
      //!                         \li 12: Dynamikmodell nicht aktiv
      //!
      //! \retval ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED gem. Madas keine Modell vorhanden
      //! \retval ROBOT_ERROR         Modell konnte nicht initialisiert werden.
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL setLoadA2(const double Mass, const ml_CFrame &CenterOfMass, const ml_CVector3 &Inertia, int *Error = 0);

      //! \brief Setzen der Zusatzlastdaten auf Achse 3
      //!
      //! \param[in] Mass         Masse auf Achse 3 [kg]
      //! \param[in] CenterOfMass Lastschwerpunkt bzgl. Flansch [mm]
      //! \param[in] Inertia      Haupttraegheiten bzgl. Lastschwerpunkt
      //!                         (Ixx, Iyy, Izz) [kgm^2]
      //!
      //! \param[out] Error       Fehlercode (identisch mit HFPFillReturnCode):
      //!                         \li  0: Dyndat-Strukturen erfolgreich gef�llt
      //!                         \li  2: Nicht implementierte Kinematik
      //!                         \li  9: Unbekannter GWA-Typ
      //!                         \li 10: Abweichung zwischen \$DYN_DAT[] und den Trafo-Daten
      //!                         \li 11: Momentenkennlinie ung�ltig
      //!                         \li 12: Dynamikmodell nicht aktiv
      //!
      //! \retval ROBOT_MADA_INVALID  Maschinendaten ung�ltig.
      //! \retval ROBOT_DYNAMIC_MODEL_NOT_CONFIGURED gem. Madas keine Modell vorhanden
      //! \retval ROBOT_ERROR         Modell konnte nicht initialisiert werden.
      //! \retval ROBOT_OK            Kein Fehler
      ROBOT_RETVAL setLoadA3(const double Mass, const ml_CFrame &CenterOfMass, const ml_CVector3 &Inertia, int *Error = 0);

      //! \brief Abkoppeln einer Zusatzachse (\$ASYNC_EX_AX_DECOUPLE)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  extAxIdx     Index der extenen Achse (0...5).
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  extAxIdx unzul�ssig
      //! \retval     ROBOT_OK              Achse abgekoppelt
      ROBOT_RETVAL setExtAxisDecoupled(int extAxIdx);

      //! \brief Ankoppeln einer Zusatzachse (\$ASYNC_EX_AX_DECOUPLE)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  extAxIdx     Index der extenen Achse (0...5).
      //!
      //! \retval     ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID extAxIdx unzul�ssig
      //! \retval     ROBOT_ERROR          Achse kann nicht angekoppelt werden
      //! \retval     ROBOT_OK             Achse angekoppelt
      ROBOT_RETVAL setExtAxisCoupled(int extAxIdx);

      //! \brief Setzen einer Zusatzachse auf asynchron (\$ASYNC_AXIS)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  extAxIdx     Index der extenen Achse (0...5).
      //!
      //! \retval     ROBOT_MADA_INVALID    Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID  extAxIdx unzul�ssig
      //! \retval     ROBOT_OK              Achse asynchron geschalten
      ROBOT_RETVAL setExtAxisAsynchron(int extAxIdx);

      //! \brief Setzen einer Zusatzachse auf synchron (\$ASYNC_AXIS)
      //!
      //! \attention
      //! Bevor diese Routine angewendet werden kann, m�ssen die Maschinendaten
      //! geladen worden sein.
      //!
      //! \param[in]  extAxIdx     Index der extenen Achse (0...5).
      //!
      //! \retval     ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval     ROBOT_INPUTS_INVALID extAxIdx unzul�ssig
      //! \retval     ROBOT_ERROR          Achse kann nicht synchron geschalten werden
      //! \retval     ROBOT_OK             Achse synchron geschalten
      ROBOT_RETVAL setExtAxisSynchron(int extAxIdx);

      //! \brief \$ECO_LEVEL setzen.
      //!
      //! \param[in]  ecoLevel \$ECO_LEVEL mit diesem Wert beschreiben.
      //! \retval     ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setEcoLevel(EEcoLevel ecoLevel);

      //! \brief \$CP_STATMON setzen.
      //!
      //! \param[in]  cpStatmon  \$CP_STATMON mit diesem Wert beschreiben.
      //! \retval     ROBOT_MADA_INVALID   Maschinendaten ung�ltig
      //! \retval     ROBOT_OK      Kein Fehler
      ROBOT_RETVAL setCpStatmon(ECpStatmon cpStatmon);
};


//! \brief   Exception-Klasse, um \b interne Fehler des Maschinedatenladers
//!          zu propagieren.
//!
//! Ein MadaInternalErrorExc-Objekt kann von allen Methoden der Klasse CRobotBase
//! bzw. CRobot geworfen werden. Die Exception wird geworfen, wenn ein interner
//! Fehler mit EXTENDED_INTERNAL_ERROR (INTERNAL_ERROR in der KRC) innerhalb des
//! Maschinedatenladers (oder an anderer Stelle) geworfen wird.
class _DLL_ MadaInternalErrorExc
{
    private:

       enum { MAX_FILENAME_LEN = 255 };

       int _param;
       int _lineno;
       char _errormessage[1024 + 1];
       char _filename[MAX_FILENAME_LEN + 1];

    public:
       //! \brief Konstruktor
       MadaInternalErrorExc(int param, const char *filename, int lineno,
                            const char *errormessage = "");

       //! \brief Name des Sourcefiles zur�ckliefern, in welchem der interne Fehler
       //!        abgesetzt wurde.
       //!
       //! \retval Dateiname
       const char* getFilename() const
       {
          return _filename;
       }

       //! \brief Zeilennummer im Sourcecode zur�ckliefern, wo der interne Fehler
       //!        abgesetzt wurde.
       //!
       //! \retval Zeilennummer
       int getLineNo() const
       {
          return _lineno;
       }

       //! \brief Optionalen Fehlercode/Parameter des internen Fehlers auslesen
       //!
       //! \retval Fehlercode
       int getParam() const
       {
          return _param;
       }

       //! \brief Error-Message des geworfenen internen Fehlers auslesen
       //!        (enth�lt ggf. n�here Fehlerursachen wie z.B. falsche
       //!         Maschinendaten)
       //!
       //! \retval Error-Message
       const char* getErrorMessage() const
       {
          return _errormessage;
       }

       //! \brief Gibt den Fehlertext mit Datei und Zeilennummer auf der
       //!        Konsole aus und schreibt gleichzeitig in Datei
       void outputError();
};


//! \brief Hilfsfunktion f�r nicht absolutgenauen Vorw�rtstransformation
//!        Setzt Tool, Base und IpoMode im �bergebenen myRobot-Objekt und
//!        ruft damit myRobot.Forward(..) auf.
//!
//! \attention
//! \li Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
//!     geladen und die Transformation �ber den Aufruf von configureTrafo()
//!     konfiguriert worden sein.
//! \li Das neue Tool, Base und IpoMode werden im Roboterobjekt(myRobot)
//!     dauerhaft gesetzt
//!
//! \param[in,out]  myRobot     Objekt vom Typ CRobot (wird modifiziert!!!)
//! \param[in]      Tool        Toolsystem (analog \$TOOL)
//! \param[in]      Base        Basesystem (analog \$BASE)
//! \param[in]      IpoMode     Interpolationsmodus (analog \$IPO_MODE)
//! \param[in]      AxisInput   Achswinkel in Grad bzw. mm (analog E6Axis)
//! \param[out]     CartOutput  Kartesische Position (analog E6Pos)
//!
//! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED Trafo nicht konfiguriert
//! \retval ROBOT_INPUTS_INVALID Inputdaten (aktive Achsen) unvollst�ndig
//! \retval ROBOT_ERROR Transformation konnte nicht durchgef�hrt werden
//! \retval ROBOT_OK    Kein Fehler
_DLL_ ROBOT_RETVAL Forward(CRobot &myRobot,
                           const ml_CFrame &Tool,
                           const ml_CFrame &Base,
                           const EIpoMode IpoMode,
                           const CAxisPosition& AxisInput,
                           CCartesianPosition& CartOutput);


//! \brief Hilfsfunktion f�r nicht absolutgenauen R�ckw�rtstransformation
//!        Setzt Tool, Base und IpoMode im �bergebenen myRobot-Objekt und
//!        ruft danach die myRobot.Backward(..) auf.
//!
//! \attention
//! \li Bevor diese Routine angewendet werden kann m�ssen die Maschinendaten
//!     geladen und die Transformation �ber den Aufruf von configureTrafo()
//!     konfiguriert worden sein.
//! \li Das neue Tool, Base und IpoMode werden im Roboterobjekt(myRobot)
//!     dauerhaft gesetzt
//!
//! \param[in,out]  myRobot     Objekt vom Typ CRobot (wird modifiziert!!!)
//! \param[in]      Tool        Toolsystem (analog \$TOOL)
//! \param[in]      Base        Basesystem (analog \$BASE)
//! \param[in]      IpoMode     Interpolationsmodus (analog \$IPO_MODE)
//! \param[in]      CartInput   Kartesische Position (analog E6Pos)
//! \param[out]     AxisOutput  Achswinkel in Grad bzw. mm (analog E6Axis)
//!
//! \retval ROBOT_TRANSFORMATION_NOT_CONFIGURED Trafo nicht konfiguriert
//! \retval ROBOT_INPUTS_INVALID Inputdaten (Frame, Status) unvollst�ndig
//! \retval ROBOT_ERROR Transformation konnte nicht durchgef�hrt werden
//! \retval ROBOT_OK    Kein Fehler
_DLL_ ROBOT_RETVAL Backward(CRobot &myRobot,
                            const ml_CFrame &Tool,
                            const ml_CFrame &Base,
                            const EIpoMode IpoMode,
                            const CCartesianPosition& CartInput,
                            CAxisPosition& AxisOutput);

#endif  // KUKA_ROBOT_H
