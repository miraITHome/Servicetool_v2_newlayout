#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void addPoint(double x, double y);
        void addXYPoint(double x, double y);
        void addPoint2(double y);
        void clearData();
        void plot();

        void addPoint_2(double x, double y);
        void addXYPoint_2(double x, double y);
        void addPoint2_2(double y);
        void clearData_2();
        void plot_2();

    private:
        Ui::MainWindow *ui;

    private slots:
        void vacaddcmd();           // wird von polltimer angesprungen bei Timeout
        void testchart();
    //    void centerAndResize();
    //    int getScreenWidth();
        bool eventFilter(QObject *object, QEvent *event);
        void setSend(void);
       // void on_pushReadboardsClicked();
        void list_COMPORTS();
        void setfuicombo(QString cmd);
        void setfuicombo_2(QString cmd);
        void on_b_connect_feeder_clicked();
        void on_b_connect_Micro_clicked();
        void on_b_connect_Stage_clicked();
        void on_b_connect_DUE_clicked();
        void on_b_connect_api_clicked();
        void connectSMIF2(int state);
        void f_setAPIPort();
        void on_combo_portlist_feeder_currentTextChanged(const QString &arg1);
        void on_combo_portlist_Micro_currentTextChanged(const QString &arg1);
        void on_combo_portlist_Stage_currentTextChanged(const QString &arg1);
        void on_combo_portlist_DUE_currentTextChanged(const QString &arg1);
        void on_combo_portlist_api_currentTextChanged(const QString &arg1);
        void on_p_INIT_refreshports_clicked();
        void on_p_INIT_resetcmdfeeder_clicked();
        void on_p_INIT_boxRAC_clicked();
        void serialReceivedFeeder();
        void serialReceived_Api();
        void serialReceived_stage();
        void serialReceived_DUE();
        void serialReceived_SMIF2();
        void serialSendFeeder(QByteArray arg);
        void serialSendAPI(QByteArray arg);
        void serialSendStage(QByteArray arg);
        void serialSendDUE(QByteArray arg);
        void serialSendMic(QByteArray arg);
        void f_receiveX2(QByteArray str);
        void f_receiveAPI(QByteArray str);
        void f_receiveSVC(QByteArray str);
        void f_receiveLOG(QByteArray str);
        void f_rec_ASYS_SMIF(QByteArray str);
        void f_rec_ISE_SMIF(QByteArray str);
        int f_errtext(int nr);
        void f_APIid(QString apidata, bool err);
        void f_apitestpolling();
        void serialReceived_Mic();
        // -------- Stylesheets -----------
        void setStyleSheets();
        void setStyleSheetFrames();
        void APIstatus();
        void resetstagecmd();
        void on_check_voltagedc_clicked(bool checked);
        void on_check_Temperatur_clicked(bool checked);
        void on_check_Sensor_clicked(bool checked);
        void on_check_vac_clicked(bool checked);
        void on_check_motvoltage_clicked(bool checked);
        void on_check_WaferSensor_clicked(bool checked);
        void on_check_ports_clicked();
        void on_check_wolamp_clicked(bool checked);
        void on_check_VacSwitch_clicked(bool checked);
        void setRadioCass(int size);
        // ------------- System polling ------------------
        void pollDC();
        void pollTP();
        void pollVAC();
        void pollSEN();
        void pollWS();
        void pollMV();
        void pollVV();
        void pollcmd();
        void pollEMO();
        void stopTimer();
        // ---------------- TESTDATA ----------------------
        void on_p_aligntestdata_clicked();
        void on_p_testdata_send_clicked();
        void on_spin_testdata_set_valueChanged(const QString &arg1);
        void on_p_data_show_clicked();
        void f_showdata(QString datastr);
        void test();
        void SETUP_FILE(const QString &arg1);
        QString converttower(QString text);
        QString reconverttower(QString text);
        QString INIconverttower(QString text);
        // ---------------- INIT ----------------------
        void f_setRESlabels(int axis);
        // ------------------ EEPROM -----------------------------
        void SETUP_STAGEFILE();
        void SETUP_CASStype(bool copy);
        void SETUP_FILE_partCASS(int cassnr);
        void SETUP_FILE_partLIFT(int liftnr);
        void SETUP_FILE_partPA();
        void SETUP_FILE_partWC();
        //void SETUP_FILE_partTOWER();
        void SETUP_FILE_partLD();
        void SETUP_FILE_partVAC(bool store);
        void SETUP_FILE_partLOCK(int liftnr, bool store);
        void SETUP_FILE_partWOBJOY();
    //    void xxxSTORE_value(const QString &arg1,const QString &arg2, const QString &arg3);
        void STORE_FILE_partCASS(int cassnr);
        void STORE_FILE_partLIFT(int liftnr);
        void STORE_FILE_partPREAS();
        void STORE_FILE_partLOADER();
        void STORE_FILE_partWC();
        //void STORE_FILE_partTOWER();
        void STORE_FILE_partVAC();
        void STORE_FILE_partLOCK(int liftnr);
        void STORE_FILE_partWOBJOY();
        void Store_File_Mot(int motor);
        void writeEEPROMcomplete();
        //------------------- Systemdata --------------------------
        void resetFlags();
        void setFlags(int flag);
        void err_lineinput(int err);
        void err_msgbox(QString box);
        int msgboxOK(QString box);
        void err_msgboxplus(QString box);
        void err_msgboxplusOK(QString box);
        void err_msgboxSysSenscalOK(QString box);
        void err_msgboxSensorHeightLift1(QString box);
        void err_msgboxSensorHeightLift2(QString box);
        // void err_msgboxplus_clean(QString box);
        // void err_msgboxplus_cleanchuck(QString box);
        // void err_msgboxplus_sequence_0(QString box);
        // int err_msgboxplus_sequence_1(QString box);
        // int err_msgboxplus_sequence_2(QString box);
        // int err_msgboxplus_sequence_3(QString box);
        // void err_msgboxplus_sequence_4(QString box);
        // void err_msgboxplus_sequence_5(QString box);
        // void err_msgboxplus_sequence_6(QString box);
        // void err_msgboxplus_sequence_7(QString box);
        void on_p_loadinsmotorini_clicked();
        void on_p_loadinssetupini_clicked();
    //    void on_p_INIT_saveMOT_clicked();
    //    void on_p_INIT_saveMOT_2_clicked();
        void on_p_INIT_saveEPROM_clicked();
        void MotparaReadVersion(QString file);
        void cleararray();
        void setEngineValues(const QString &arg1);
        void setRESLabelRed();
        void t_part_clear();
        void t_part_ee(int lines);
        void t_part_ee_mot(int cntlines,int cntdata);
        void t_part_ee_insmotor(QString line,int cnt);
        void setCassData(QByteArrayList(parts));
        void copy_FILE_partCASS(int source, int dest);
        void sendREAD(QString nr);
        QString getResolution(QString name);
        void L1_conv2mm();
        void L1_conv2steps();
        void L2_conv2mm();
        void L2_conv2steps();
        void changeWidget(QString name);
        QString f_asc2num(QString asc);
   //     void f_setSlidecolor();
    //------------------- Register LIFT 1 --------------------
            void on_check_tilt1_deactivate_stateChanged(int arg1);
            void on_push_lift1_cassswitch_clicked();
            void on_push_lift1_engine_clicked();
            void on_push_lift1_init_height_clicked();
            void on_push_lift1_init_tilt_clicked();
            void on_push_lift1_lock_clicked();
            void on_push_lift1_store_clicked();
            void on_push_lift1_upload_clicked();
            void on_radio_lift1_addtohgt_clicked(bool checked);
            void on_p_LDheight_xy_clicked();
            void on_p_wafersensor_height_clicked();
            void on_p_oper_height_clicked();
            void on_p_tilt_active_clicked();
            void on_p_tilt_inactive_clicked();
            void on_check_lift1_moveconst_stateChanged();
            void on_push_lift1_editcass_clicked();
            void on_p_lift1_constpos_up_tilt_pressed();
            void on_p_lift1_constpos_up_tilt_released();
            void on_p_lift1_constpos_down_tilt_pressed();
            void on_p_lift1_constpos_down_tilt_released();
            void on_line_lift1_measuring_height_textChanged(const QString &arg1);
            void on_radio_lift1_SMIF_clicked(bool checked);
            void on_radio_lift1_default_clicked(bool checked);
            void on_radio_lift1_notinstalled_clicked(bool checked);
            void on_push_lift1_store_2_clicked();
            void on_p_lift1_constpos_up_pressed();
            void on_p_lift1_constpos_up_released();
            void on_p_lift1_constpos_down_pressed();
            void on_p_lift1_constpos_down_released();
            void on_push_lift1_cal_sensheight_clicked();
            void on_push_lift1_cal_intensity_clicked();
            void on_p_L1_gettilt_clicked();
            void on_spinL1_stepwidth_tilt_textChanged(const QString &arg1);
            void on_p_L1_getheight_clicked();
            void on_p_lift1_SMIF_clicked();
    //------------------- Register LIFT 2 --------------------
            void on_check_tilt2_deactivate_stateChanged(int arg1);
            void on_check_lift2_deactivate_stateChanged(int arg1);
            void on_p_lift2_init_height_clicked();
            void on_p_lift2_init_tilt_clicked();
            void on_push_lift2_cassswitch_clicked();
            void on_push_lift2_engine_clicked();
            void on_push_lift2_lock_clicked();
            void on_push_lift2_store_clicked();
            void on_push_lift2_upload_clicked();
            void on_radio_lift2_addtohgt_clicked(bool checked);
            void on_p_LDheight_xy_2_clicked();
            void on_p_wafersensor_height_2_clicked();
            void on_p_oper_height_2_clicked();
            void on_p_tilt_active_2_clicked();
            void on_p_tilt_inactive_2_clicked();
            void on_check_lift2_moveconst_stateChanged();
            void on_push_lift2_editcass_clicked();
            void on_p_lift2_constpos_up_tilt_pressed();
            void on_p_lift2_constpos_up_tilt_released();
            void on_p_lift2_constpos_dwn_tilt_pressed();
            void on_p_lift2_constpos_dwn_tilt_released();
            void on_line_lift2_measuring_height_textChanged(const QString &arg1);
            void on_radio_lift2_SMIF_clicked(bool checked);
            void on_radio_lift2_default_clicked(bool checked);
            void on_radio_lift2_notinstalled_clicked(bool checked);
            void on_push_lift2_store_2_clicked();
            void on_p_lift2_constpos_up_pressed();
            void on_p_lift2_constpos_up_released();
            void on_p_lift2_constpos_down_pressed();
            void on_p_lift2_constpos_down_released();
            void on_push_lift2_cal_senshgt_clicked();
            void on_push_lift2_cal_intensity_clicked();
            void on_p_L2_getheight_clicked();
            void on_p_lift2_SMIF_clicked();
            void on_p_L2_gettilt_clicked();
        //------------------- Loader -------------------------
            void LD_conv2mm();
            void LD_conv2steps();
            void on_p_LD_Xlift1_clicked();
            void on_p_LD_Xlift2_clicked();
            void on_p_LD_XPA_clicked();
            void on_p_LD_PAfree_clicked();
            void on_p_LD_Yinlift1_clicked();
            void on_p_LD_Yinlift2_clicked();
    //        void on_p_LD_Ydispl_clicked();
            void on_p_LD_Yout_clicked();
            void on_p_LD_Ypapos_clicked();
            void on_p_loader_engine_clicked();
            void on_p_loader_initxdrive_clicked();
            void on_p_loader_initydrive_clicked();
            void on_p_loader_store_clicked();
            void on_p_ld_constpos_left_pressed();
            void on_p_ld_constpos_left_released();
            void on_p_ld_constpos_right_pressed();
            void on_p_ld_constpos_right_released();
            void on_p_ld_constpos_in_pressed();
            void on_p_ld_constpos_in_released();
            void on_p_ld_constpos_out_pressed();
            void on_p_ld_constpos_out_released();
    //------------------- Register PREALIGNER ----------------
            void PA_conv2mm();
            void PA_conv2steps();
            void on_p_INIT_PA_Height_clicked();
            void on_p_INIT_PA_Phi_clicked();
            void on_p_INIT_PA_RotPos_clicked();
            void on_p_INIT_PA_Tilt_clicked();
            void on_p_PA_store_clicked();
            void on_p_aligner_engine_clicked();
            void on_line_align_setconst_cursorPositionChanged(int arg1, int arg2);
            void on_check_align_constpos_2_stateChanged();
            void on_check_align_constpos_4_stateChanged();
            void on_check_align_constpos_3_stateChanged();
            void on_check_woturn_clicked(bool checked);
            void on_check_preaturn_clicked(bool checked);
            void on_p_PA_abovLDhgt_clicked();
            void on_p_PA_LDhgt_clicked();
            void on_p_PA_belowLDhgt_clicked();
            void on_p_PA_CHhgt_clicked();
            void on_p_PA_hgt_clicked();
            void on_p_PA_SnesAngle_clicked();
            // void on_p_PA_count_clicked();
            // void on_p_PA_precount_clicked();
            // void on_p_PA_postcount_clicked();
            void on_p_PA_WOtilt_clicked();
            void on_p_PA_WOrotpos_clicked();
            void on_p_PA_getTilt_clicked();
            void on_p_PA_getRot_clicked();
            void on_p_align_constpos_height_up_pressed();
            void on_p_align_constpos_height_up_released();
            void on_p_align_constpos_height_dwn_pressed();
            void on_p_align_constpos_height_dwn_released();
            void on_p_align_constpos_phi_cw_pressed();
            void on_p_align_constpos_phi_cw_released();
            void on_p_align_constpos_phi_ccw_pressed();
            void on_p_align_constpos_phi_ccw_released();
            void on_p_align_constpos_tilt_up_pressed();
            void on_p_align_constpos_tilt_up_released();
            void on_p_align_constpos_tilt_dwn_pressed();
            void on_p_align_constpos_tilt_dwn_released();
            void on_p_align_constpos_rot_cw_pressed();
            void on_p_align_constpos_rot_cw_released();
            void on_p_align_constpos_rot_ccw_pressed();
            void on_p_align_constpos_rot_ccw_released();
    //------------------- Register WAFERCHANGER --------------
            void WC_conv2mm();
            void WC_conv2steps();
            void on_check_wc_deactivate_stateChanged(int arg1);
            void on_p_WC_abovCHhgt_clicked();
            void on_p_WC_CHhgt_clicked();
            void on_p_WC_belowCHhgt_clicked();
            void on_p_WC_left_clicked();
            void on_p_WC_middle_clicked();
            void on_p_WC_right_clicked();
            void on_p_wc_engine_clicked();
            void on_p_wc_initangle_clicked();
            void on_p_wc_initheight_clicked();
            void on_p_wc_store_clicked();
            void wc_pos_chuckhgt();
            void wc_pos_abovechuckhgt();
            void wc_pos_middle();
            void wc_pos_left();
            void on_check_WC_moveconst_stateChanged();
            void on_p_wc_constpos_up_pressed();
            void on_p_wc_constpos_dwn_released();
            void on_p_wc_constpos_phi_cw_pressed();
            void on_p_wc_constpos_phi_ccw_released();
            void on_p_wc_constpos_up_released();
            void on_p_wc_constpos_dwn_pressed();
            void on_p_wc_constpos_phi_cw_released();
            void on_p_wc_constpos_phi_ccw_pressed();
        //------------------- Clean ---------------------------
            void f_cleanmacro_vac();
            void on_p_clean_waferdetection_clicked();
            void clean_stagepos();
            void f_clean_reset(int unit);
            void f_cleanGetPos();
            //------------------- Register VAC -----------------------
            void on_check_vac_loader_2_clicked(bool checked);
            void on_check_vac_aligner_2_clicked(bool checked);
            void on_check_vac_wcright_2_clicked(bool checked);
            void on_check_vac_wcleft_2_clicked(bool checked);
            void on_check_vac_chuck4_2_clicked(bool checked);
            void on_check_vac_chuck6_2_clicked(bool checked);
            void on_check_vac_chuck8_2_clicked(bool checked);
            void on_p_RES_L1_Height_clicked();
            void on_p_RES_L1_Tilt_clicked();
            void on_p_RES_L2_Height_clicked();
            void on_p_RES_L2_Tilt_clicked();
            void on_p_RES_LOADER_X_clicked();
            void on_p_RES_LOADER_Y_clicked();
            void on_p_RES_PREA_Height_clicked();
            void on_p_RES_PREA_PHI_clicked();
            void on_p_RES_PREA_TILT_clicked();
            void on_p_RES_PREA_ROTPOS_clicked();
            void on_p_RES_WC_P_clicked();
            void on_p_RES_WC_H_clicked();
            void on_p_RES_L1_Height_2_clicked();
            void on_p_RES_L1_Tilt_2_clicked();
            void on_p_RES_L2_Height_2_clicked();
            void on_p_RES_L2_Tilt_2_clicked();
            void on_p_RES_LOADER_X_2_clicked();
            void on_p_RES_LOADER_Y_2_clicked();
            void on_p_RES_PREA_Height_2_clicked();
            void on_p_RES_PREA_PHI_2_clicked();
            void on_p_RES_PREA_TILT_2_clicked();
            void on_p_RES_PREA_ROTPOS_2_clicked();
            void on_p_RES_WC_P_2_clicked();
            void on_p_RES_WC_H_2_clicked();
            void on_combo_motorselect_currentTextChanged(const QString &arg1);
            void on_push_mot_readrac_clicked();
            void on_push_mot_try_clicked();
            void on_push_mot_store_clicked();
            void on_p_recalc_clicked();
            void on_p_Invent_Lift1_clicked();
            void on_p_Invent_Lift2_clicked();
            void on_p_pollPos_clicked();
            void f_setVAClabels(int channel);
    //------------------- Widget MOTORDATA ------------------
            void on_p_motstat_LOADER_Y_clicked();
            void on_p_motstat_LOADER_X_clicked();
            void on_p_motstat_L1_Height_clicked();
            void on_p_motstat_L1_Tilt_clicked();
            void on_p_motstat_L2_Height_clicked();
            void on_p_motstat_L2_Tilt_clicked();
            void on_p_motstat_PREA_Height_clicked();
            void on_p_motstat_PREA_PHI_clicked();
            void on_p_motstat_PREA_TILT_clicked();
            void on_p_motstat_PREA_ROTPOS_clicked();
            void on_p_motstat_WCH_clicked();
            void on_p_motstat_WCP_clicked();
    //------------------- Widget CASS ------------------------
            void on_checkCass_lift1_clicked(bool checked);
            void on_checkCass_lift2_clicked(bool checked);
            void on_push_wid_cass_Calib_clicked();
            void on_push_wid_cass_Unload_clicked();
            void on_push_wid_cass_load_clicked();
            void on_comboCass_Type_activated(int index);
            void on_push_wid_cass_Store_clicked();
            void on_p_cass_firstslot_clicked();
            void on_p_cass_distanz_clicked();
            void on_p_cass_wafoffset_clicked();
            void on_p_cass_fingeroffset_clicked();
            void on_p_cass_slotssize_clicked();
            void on_p_cass_wafsize_clicked();
            void on_p_cass_slottpos_clicked();
            void on_spinCass_firstSlot_textChanged(const QString &arg1);
            void on_spinCass_SlotDist_textChanged(const QString &arg1);
            void on_spinCass_WafheightOff_textChanged(const QString &arg1);
            void on_spinCass_fingerHeightOff_textChanged(const QString &arg1);
            void on_spinCass_SlotWdw_textChanged(const QString &arg1);
            void on_spinCass_WafSizeWdw_textChanged(const QString &arg1);
            void on_spinCass_SlotPos_textChanged();
            void on_p_cass_getheight_clicked();
            void on_p_cass_constpos_pressed();
            void on_p_cass_constpos_released();
            //------------------- Widget TESTPROGRAM -----------------
            //------------------- Widget LIFT LOCK -------------------
            void on_p_lock_lock_clicked();
            void on_p_lock_unlock_clicked();
            void on_p_lock_lock_2_clicked();
            void on_p_lock_unlock_2_clicked();
            void on_p_lock_upload_2_clicked();
            void on_p_lock_download_2_clicked();
            void on_p_lock_upload_clicked();
            void on_p_lock_download_clicked();
            //------------------- Widget RESET ----------------
            // _________________ Widget XRAC _____________________________
            void hidedatabox();
            void on_combo_cmd_currentIndexChanged(const QString &arg1);
            void on_p_break_clicked();
            void on_p_xrac_send_clicked();
            void on_combo_node_currentIndexChanged(const QString &arg1);
            void on_combo_fui_currentIndexChanged(const QString &arg1);
            void on_combo_su_activated(int index);
            void on_combo_mu_activated(int index);
            void showMessageData();
            void showMessageData_2();
            void on_check_param1_clicked();
            void on_check_param2_stateChanged();
            void on_check_lift1_deactivate_stateChanged(int arg1);
            void on_line_data1_editingFinished();
            void on_line_data2_editingFinished();
            void on_line_data3_editingFinished();
            void on_line_data4_editingFinished();
            void on_line_data5_editingFinished();
            void on_line_data6_editingFinished();
            void on_line_data7_editingFinished();
            void on_line_data8_editingFinished();
            void on_line_data9_editingFinished();
            void on_line_data10_editingFinished();
            void on_line_data11_editingFinished();
            void on_line_data12_editingFinished();
            void on_line_data13_editingFinished();
            void on_line_data14_editingFinished();
            void on_line_data15_editingFinished();
            void on_line_data16_editingFinished();
            void on_line_data17_editingFinished();
            void on_line_data18_editingFinished();
            void on_line_data19_editingFinished();
            void on_p_XRAC_clear_clicked();
            // ------------------ Widget Aligner ---------------------------
            void on_p_align_cal_clicked();
            void on_p_align_analogval_clicked();
            void on_check_repeat_2_stateChanged(int arg1);
            void on_p_align_amplif_clicked();
            void on_p_align_constpos_clicked();
            void on_p_align_transmitstart_clicked();
            void on_p_align_setamplif_clicked();
            void on_p_align_resphi_clicked();
            void on_p_align_getpos_clicked();
            void on_p_pa_vac_clicked();
            void on_p_align_setpos_clicked(bool ext);
            void showspline();
            void showspline_2();
    //        void on_p_plotclear_clicked();
            void on_p_align_getslitlen_clicked();
            void on_p_align_setslitlen_clicked();
            void on_p_align_runmacro_lddispl_clicked();
            void on_p_align_getdispl_clicked();
            void on_p_align_setdispl_clicked();
            void on_p_align_displpos_clicked();
            void on_p_align_getsetupdispl_clicked();
            void on_p_align_setsetupdispl_clicked();
            void on_p_align_runmacro_clicked();
            void on_p_align_getwafangle_clicked();
            void on_p_align_setwafangle_clicked();
            void on_p_align_getfilter_clicked();
            void on_p_align_setfilter_clicked();
            void on_p_align_waferchange_clicked();
            void on_p_align_setflatlen_clicked();
            void on_p_align_getflatlen_clicked();
            void on_p_align_getwafsize_clicked();
            void on_p_align_setwafsize_clicked();
            void on_p_align_getfnidcorr_clicked();
            void on_p_align_setfnidcorr_clicked();
            void on_p_align_getpaangle_clicked();
            void on_p_align_setpaangle_clicked();
            void on_p_align_runmacro_decenter_clicked();
    // ---------- API --------------------------
            void on_pINIT_clicked();
            void on_push_loader_upload_clicked();
            void on_push_PA_upload_clicked();
            void on_groupBox_Lift1_clicked();
            void on_groupBox_Lift2_clicked();
            void on_p_selectall1_toggled(bool checked);
            void on_p_selectall2_toggled(bool checked);
            int listselwafer();
            void actslot(int slot);
            void deselslot();
            void on_checkBox_simulation_stateChanged(int arg1);
            void on_p_help_clicked();
            void on_push_WC_upload_clicked();
            void on_check_sensor_loop_stateChanged();
            void deletslots(int liftnr);
            void on_tabWidget_tabBarClicked(int index);
            void serializePosData(QByteArray *arr,QLineEdit *line);
            void serializeWord(QByteArray *arr, QLineEdit *line);
            void on_push_clear_clicked();
            void on_check_LaserIntensity_clicked();
            void on_p_API_Get_clicked();
            void API_getwafer();
            void on_p_API_Align_clicked();
            void on_p_API_ALROT_clicked();
            void on_p_API_PREWC_clicked();
            void doAPI_WC();
            void on_p_API_Put_clicked();
            void on_p_angle2encsteps_clicked();
            void on_push_mot_readrac_2_clicked();
            void on_p_SET_EE_STR_clicked();
            void on_p_transfer_stage_calib_clicked();
            void on_p_transfer_store_clicked();
            void on_p_WC_CHhgt_2_clicked();
            void on_p_WC_left_2_clicked();
            void on_p_WC_middle_2_clicked();
            void on_p_WC_abovCHhgt_2_clicked();
            void on_p_INIT_boxreset_clicked();
            void data_SetMotPara();
            void on_push_mot_try_2_clicked();
            void on_p_L1H_start_clicked();
            void on_p_api_setcar_clicked();
            void on_p_API_IN_clicked();
            void on_p_API_Stat_clicked();
            void on_p_API_OUT_clicked();
            void on_p_API_logerr_clear_clicked();
            void on_p_API_logerr_clear_2_clicked();
            void on_p_API_Getalrot_clicked();
            void assistant_API_getwafer();
            void assistant_API_setcar();
            void assistant_API_LOAD();
            void assistant_loop(int loop);
            void assistant_API_Align();
            void assistant_API_putwafer();
            void on_p_API_GetFNres_clicked();
            void on_p_API_START_clicked(bool checked);
            void api_loop();
            void on_p_API_Get_2_clicked();
            void on_p_API_Put_2_clicked();
            void on_p_API_PREWC_down_clicked();
            void on_p_API_putaligner_clicked();
            void on_p_API_UPDATEMACRO_clicked();
            void on_p_API_Getwobbler_clicked();
            void on_p_API_getaligner_clicked();
            void on_p_API_GETOUT_clicked();
            void on_p_API_UNLOAD_clicked();
            void on_p_API_SETMACRO_clicked();
            void on_p_API_STOPMACRO_clicked();
            void API_putwafer();
    // ----------------- dev --------------------
            void on_p_ldx_constpos_clicked();
            void on_p_ldy_constpos_clicked();
            void on_p_l1h_constpos_clicked();
            void on_p_l1t_constpos_clicked();
            void on_p_l2h_constpos_clicked();
            void on_p_l2t_constpos_clicked();
            void on_p_pah_constpos_clicked();
            void on_p_pap_constpos_clicked();
            void on_p_pat_constpos_clicked();
            void on_p_par_constpos_clicked();
            void on_p_wch_constpos_clicked();
            void on_p_wcp_constpos_clicked();
            void dev_posconst(QByteArray constpos);

            void on_check_pospositiv_stateChanged();

            void on_p_constpos_stop_clicked();

            void on_check_PA_moveconst_stateChanged();

            // void on_check_LD_moveconst_stateChanged();

            void serialPosData(QByteArray *arr, int val);

            void on_p_setup_clearlog_clicked();

            void on_p_INIT_logclear_warn_clicked();

            void on_p_PA_getheight_clicked();

            void on_p_WC_getheight_clicked();

            void f_lineFocusOut(QLineEdit *line);

            void on_p_dev_sync_clicked();

            void on_p_log_fifo_clicked();

            void on_p_pos_stage_transfer_clicked();

            void on_p_stage_getpos_clicked();

            void on_p_LD_getXpos_clicked();

            void on_p_LD_getYpos_clicked();

            void on_p_PA_getPhi_clicked();
            void on_p_Invent_GETMAP_clicked();

            void on_p_vac_download_clicked();
            void on_p_vac_upload_clicked();

            void on_spinL2_stepwidth_tilt_textChanged(const QString &arg1);

            void on_p_WC_getPhi_clicked();

            void on_p_help_engine_clicked();

            void on_p_help_cass_clicked();

            void on_p_readCassParam_clicked();
            void macrostep(uint8_t mstep);
            void macrostep_lddispl(uint8_t step);

            void on_p_copyCass_clicked();

            void on_p_setboardParam_clicked();

            void on_p_dev_pinc_clicked();

            void on_p_dev_ddrc_clicked();

            void on_p_dev_portc_clicked();

            QString binList(int tmpdata);

            void on_check_vac_poll_stateChanged(int arg1);

            void on_p_cass_getsize_clicked();

            void on_p_angle_zeropos_clicked();

            void on_p_dbg_clear_clicked();

            void on_p_LOGIN_clicked();

            void on_p_writeHexfile_clicked();

            void on_p_align_getws_clicked();

            void on_p_Lift_map_clicked();
            void getMap();

            void macroProfil(bool state);
            void macro_partAlign();

            void on_p_align_profile_clicked();

            void on_p_selectHexPA_clicked();
            void on_p_selectHexAPI_clicked();
            void on_p_selectHexRAC_clicked();

            void on_p_prog_reset_clicked();

            void on_p_SMIF_startISIM_clicked();

            void deactslot(int slot);

            void on_p_LDcenter_clicked();

            void on_p_stage_doxoff_clicked();
            void on_p_stage_doyoff_clicked();

            void on_p_mic_getpos_clicked();

            void on_p_mic_logerr_clear_clicked();

            void on_p_stage_logerr_clear_clicked();
            void on_p_transfer_stage_status_clicked();
            void on_check_stage_joystick_clicked(bool checked);

            void on_p_systemstate_clicked();

            void on_p_macros_openmacro_clicked();
            void on_combo_node_2_currentTextChanged(const QString &arg1);
            void on_combo_cmd_2_currentTextChanged(const QString &arg1);
            void on_combo_fui_2_currentTextChanged(const QString &arg1);

            void on_p_macros_addcmd_clicked();
            void on_p_macros_save_clicked();
            void on_p_macros_adddelay_clicked();

            void resetapicmd_clicked();
            void progTimer();
    /* ----------------- System --------------- */
            void set_Materialliste(int list);
            void set_Foundwaferliste(int list);
            void set_Resetliste(int list);
            void set_feederliste(QString data);
            void set_WCangle();
            void on_check_wc_multi_stateChanged(int arg1);
            void on_p_feederstate_clicked();
            void on_p_system_materialfound_clicked();
            void on_p_system_getresetlist_clicked();
            void on_p_system_material_clicked();
            void on_p_system_mm_clear_clicked();

            void on_p_system_found_clear_clicked();

            QString decodeRespHex(QString CMDtext);
            QString decodeFUIhex(QString FUItext);
            QString decodeMU(int mu);
            QString decodeSU(int su, int mu);
            QString decodeAPI(int api);
            //void on_p_tower_store_clicked();
            void removetab();

            void on_p_log_feederlist_clicked();

            void on_p_system_unitpos_clicked();
            void macroUnitPos(int ustep);

            void on_p_misc_sendHORN_clicked();
            void on_p_misc_sendRED_clicked();
            void on_p_misc_sendYELLOW_clicked();
            void on_p_misc_sendGREEN_clicked();
            void f_towerset(int lmp, QString tmpstr1, QString tmpstr2);

            void on_p_system_mm_set_clicked();
            void on_p_system_found_set_clicked();
            QString get_Materialliste();
            QString get_Foundwafliste();

            void on_check_wob_deactiv_toggled(bool checked);

            void on_check_EMO_clicked(bool checked);

            void on_p_macros_clear_clicked();

            void on_p_macros_runmacro_clicked();
            void f_macromaker();
            void f_macrocheck();

            void on_p_macros_clearresponse_clicked();

            void f_setsequence(int sequ);

            void on_p_API_setWOLMP_clicked();

            void on_verticalSlider_API_WOBlamp_valueChanged(int value);

            void on_p_API_LOAD_clicked();

         //   void on_radio_loader_stepsmm_clicked(bool checked);

            void on_radio_prea_stepsmm_clicked(bool checked);

            void on_radio_wc_stepsmm_clicked(bool checked);

            void on_p_dev_pospositiv_clicked();

            void on_p_LOG_clear_feederlist_clicked();

            void on_checkBox_errorlog_clicked(bool checked);

            void on_checkBox_warnlog_clicked(bool checked);

            void on_checkBox_debuglog_clicked(bool checked);

            void on_radio_log_errorstop1_clicked();

            void on_p_INIT_save_allmot_EPROM_clicked();

            void on_p_reset_microscope_clicked();

            void on_p_sys_posWCmiddle_clicked();

            void on_radio_LOG_errstop_reset_clicked();

            void on_radio_LOG_eeflag_clicked();

            void on_p_cass_setdefault_clicked();
            void on_p_cass_constpos_down_pressed();
            void on_p_cass_constpos_down_released();

            void on_p_INIT_save_allmot_boards_clicked();
            void setusertab(int idx);

            int on_p_INIT_boxreset_setup_clicked();

            void on_check_loader_releasemotoX_clicked(bool checked);
            void on_check_loader_releasemotoY_clicked(bool checked);

            void on_p_get_boardmotorparam_clicked();

            void on_p_SMIF_INIT_clicked();
            void on_p_SMIF_MAP_clicked();

            void on_p_log_servicemode_clicked(bool checked);

            void on_p_readBoard2_clicked();
            void on_p_readBoard3_clicked();
            void on_p_readBoard4_clicked();
            void on_p_readBoard5_clicked();
            void on_p_readBoard6_clicked();
            void on_p_readBoard7_clicked();
            void on_p_readBoard8_clicked();
            void on_p_readBoard9_clicked();
            void on_p_readBoard15_clicked();
            void on_p_readINSBox_clicked();

            void on_p_Invent_GETMAP_2_clicked();

            void on_checkBox_dev_WOBjoystick_clicked(bool checked);

            void on_p_start_assistant_wc_clicked();
            int err_msgboxTransferOK(QString box);

            void mic_loop();
            void on_check_MIC_selectall_stateChanged(int arg1);
            void on_p_MIC_start_clicked(bool checked);

            void on_p_FW_changeFile_clicked();
            void f_openbatch(QString script, QString file, QString file2);

            void on_p_help_changer_clicked();

            void on_p_help_aligner_clicked();

            void on_check_API_servicemode_stateChanged(int arg1);

            void on_p_cass_getheight_2_clicked();
            void f_openHelp(int page);

            void on_p_help_loader_clicked();

            void on_p_help_lift2_clicked();

            void on_p_help_lift1_clicked();

            void on_p_help_clean_clicked();

            void on_p_help_vac_clicked();
            void f_searchPage(QString part);

            void on_p_help_api_clicked();

            void on_p_help_macro_clicked();

            void on_p_help_lock_clicked();

            void on_p_help_systemdata_clicked();

            void on_p_help_buslog_2_clicked();

            void on_p_help_prog_clicked();
            void timeoutDelay();

            void on_check_loader_vacuum_clicked(bool checked);

            void on_check_wc_vacuumchuck_clicked(bool checked);

            void on_check_wc_vacuumright_clicked(bool checked);

            void on_check_wc_vacuumleft_clicked(bool checked);

            void on_check_preavac_2_clicked(bool checked);

            void on_check_preavac_clicked(bool checked);

            void on_p_SMIF_status_clicked();

            void on_p_SMIF_begin_clicked();

            void on_p_SMIF_Get_clicked();

            void on_p_SMIF_PUT_clicked();
            void SMIF_getwafer();
            void SMIF_deletslots(int liftnr);
            void SMIF_deselslot();
            int SMIF_listselwafer();
            void SMIF_actslot(int slot);
            void SMIF_deactslot(int slot);

            void on_p_smif_pconf5_clicked();

            void on_p_smif_gconf2_clicked();

            void on_p_smif_gconf5_thick_clicked();

            void on_p_system_DIAGLED_clicked();

            void on_check_api_pollingtest1_stateChanged(int arg1);
            void api_poll();

            void on_checkBox_simucount_clicked(bool checked);

            void on_checkBox_mainvacoff_stateChanged(int arg1);
            void f_decodeWarnlog(int block, int cmd, int id, int fehlernr, QString count);

            void on_p_API_twidelay_clicked();

            void on_p_API_getstate_clicked();

            void on_p_start_assistant_wc_2_clicked();

            void on_check_API_activate_assistant_stateChanged(int arg1);

            void on_check_vac_loader_4_clicked(bool checked);

            void on_check_vac_aligner_4_clicked(bool checked);

            void on_check_vac_wcleft_4_clicked(bool checked);

            void on_check_vac_wcright_4_clicked(bool checked);

            void on_check_vac_chuck4_4_clicked(bool checked);

            void on_check_vac_chuck6_4_clicked(bool checked);

            void on_check_vac_chuck8_4_clicked(bool checked);

            void on_p_clean_completereset_2_clicked();

            void on_p_sys_posWCmiddle_2_clicked();

            void on_p_INIT_logclear_debug_clicked();

            void on_p_lock_unlock_lift1_clicked();

            void on_p_lock_unlock_lift2_clicked();

            void on_p_joy_store_clicked();

            void on_p_sys_VacRefresh_clicked();
            void resCLEANflags();


            void on_checkBox_errorlog_2_clicked(bool checked);

            void on_p_API_VER_clicked();

            void on_p_help_feed_clicked();

            void on_p_set_INITflag_clicked();

            void on_p_macros_testlift1height_clicked();

            void on_p_macros_testlift1tilt_clicked();

            void on_p_macros_testlift2height_clicked();

            void on_p_macros_testlift2tilt_clicked();

            void on_p_macros_testLDX_clicked();

            void on_p_macros_testLDY_clicked();

            void on_p_macros_testPAH_clicked();

            void on_p_macros_testPAP_clicked();

            void on_p_macros_testPAR_clicked();

            void on_p_macros_testPAT_clicked();

            void on_p_macros_testWCH_clicked();

            void on_p_macros_testWCP_clicked();

            void on_p_macros_stopmacro_clicked();

            void on_checkCass_flat_clicked(bool checked);

            void on_checkCass_notch_clicked(bool checked);

            void on_check_preavac_3_clicked(bool checked);

            void on_p_FW_changeFile_2_clicked();

            void on_p_SMIF_setdelay_clicked();

            void on_p_SMIF_getdelay_clicked();

            void on_p_SMIF_clear_clicked();

            void on_p_smif_getpconf2_clicked();

            void on_p_SMIF_errorclear_clicked();
            void read_workingcass_insbox(int index);
            void logswitch(int state);

            void on_p_SMIF_end_clicked();

            void on_p_SMIF_home_clicked();

            void on_p_smif_getpconf3_clicked();

            void on_p_smif_getpconf4_clicked();

            void on_p_smif_getpconf6_clicked();

            void on_p_smif_gconf3_clicked();

            void on_p_smif_gconf4_clicked();

            void on_p_smif_gconf6_clicked();

            void on_checkBox_SMIF_option4_clicked(bool checked);

            void on_checkBox_SMIF_option6_clicked(bool checked);
            void SMIF_putwafer();

            void on_p_SMIF_Zdown_clicked();

            void on_p_SMIF_Zup_clicked();

            void on_p_SMIF_get_zstroke_clicked();

            void on_p_SMIF_set_zstroke_clicked();

            void on_p_SMIF_retract_clicked();

            void on_pushButton_SMIF_seriallog_clicked();

            void on_check_loader_releasemotoX_2_clicked(bool checked);

            void on_check_loader_releasemotoY_2_clicked(bool checked);

            void on_comboCass_Type_smif_activated(int index);

            void on_p_copyCass_smif_clicked();

            void on_push_wid_cass_Store_smif_clicked();

            void on_checkBox_SMIF_statuspoll_clicked(bool checked);
            int* dez2byte(int tmpval, int arr[]);
            void sendmacrostring(int value, QString task, QString node, QString cmd, QString fui);
            void f_stepteststring(void);

            void on_p_help_SMIF_clicked();

            void on_p_SMIF_set_Logistic_clicked();
            void on_p_SMIF_get_Logistic_clicked();

            void f_setparam_board8();
            void f_getparam_board8();
            void on_p_macros_clearresponse_posconst_clicked();

            void on_p_macros_clearresponse_posabs_clicked();

            void on_p_macros_clearresponse_readpos_clicked();

            void on_check_API_servicefriction_stateChanged(int arg1);

            void on_check_testdata_ON_clicked();

            void on_check_testdata_resetFlag_clicked();

            void on_check_testdata_sqrlog_clicked();

            void on_check_align_dataon_clicked();

            void on_check_align_rawdata_clicked();

            void on_check_switch1_clicked();

            void f_vactest();

            void on_p_vactest_start_clicked();

            void on_p_joy_getvalues_clicked();

            void on_p_SMIF_infoerrorcode_clicked();

            void on_p_SMIF_laseroutput_clicked();

            void on_p_SMIF_slotdata_clicked();

            void on_p_SMIF_counter_clicked();

            void on_p_LDcenter_2_clicked();
            void f_macros_stopmacro_clicked();

            void on_p_align_constpos_rot_cw_2_pressed();

            void on_p_align_constpos_rot_cw_2_released();

            void on_p_align_constpos_rot_ccw_2_pressed();

            void on_p_align_constpos_rot_ccw_2_released();

            void on_p_PA_getRot_2_clicked();

            void on_p_log_servicemode_simple_clicked(bool checked);

            void on_p_macros_clear_statistics_clicked();

            void on_p_SMIF_open_clicked();

            void on_p_SMIF_close_clicked();

            void on_p_SMIF_FLSWT_clicked();

            void on_p_SMIF_S_INFO_clicked();

            void on_p_SMIF_ID_clicked();

            void on_p_SMIF_IFLSWT_clicked();

            void on_p_SMIF_S_ID_clicked();

            void on_p_SMIF_SERVICEflag_clicked();

            void on_p_SMIF_S_NULL_clicked();

            void on_p_SMIF_S_AKT_clicked();

            void on_p_SMIF_S_IPOS_clicked();

            void on_p_SMIF_S_DEAKT_clicked();

            void on_p_setup_comparesetup_clicked();

            void on_p_setup_comparemotor_clicked();

            void on_p_ASYST_status_clicked();

            void on_pushButton_ASYST_seriallog_clicked();

            void on_checkBox_ASYST_statuspoll_clicked(bool checked);

            void on_p_ASYST_clear_clicked();
            void f_ASYST_slot(QLineEdit *line, QString t);

            void on_tableWidget_ASYST_readconfig_cellPressed(int row, int column);

            void on_p_ASYST_readconfig_clicked();

            void on_p_ASYST_setconfig_clicked();

            void on_p_ASYST_INIT_clicked();

            void on_p_ASYST_stage_clicked();

            void on_p_ASYST_home_clicked();

            void on_p_ASYST_stop_clicked();

            void on_p_ASYST_lock_clicked();

            void on_p_ASYST_MAP_clicked();

            void on_p_ASYST_tweek_dwn_clicked();

            void on_p_ASYST_tweek_up_clicked();

            void on_p_ASYST_unlock_clicked();

            void on_push_wid_cass_Store_ASYST_clicked();

            void on_check_loader_releasemotoX_5_clicked(bool checked);

            void on_check_loader_releasemotoY_5_clicked(bool checked);
            QString f_decode_servicecmd(QByteArray arg);

            void on_p_ASYST_reset_clicked();

signals:
        void mySignal();        // TestSignal

};

#endif // MAINWINDOW_H
