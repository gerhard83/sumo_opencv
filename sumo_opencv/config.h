#pragma once 
#include <Windows.h>

	/* SERIAL SETUP*/
#define SERIAL_COM_PORT						"COM4"					//Select COM port for serial transmission (with KF64 board which appears as "USB Serial Device" in Ports (COM&LPT))

	/* ENABLE FEATURES */
#define GENERATE_ARUCO_CODES				(0x01u)					//Generate and save Aruco Marker
#define CALIBRATE_CAMERA					(0x02u)					//Calibrate Camera
#define DETECT_MARKERS						(0x04u)					//Detect Markers

	/* SELECT PROGRAM MODE */
#define SUMO_OPENCV_MODE                    (DETECT_MARKERS)

#define SHOW_FINAL_IMAGE					(TRUE)					//Show the Live Image with detected Markers and Coordinate System. May slow down the program 
#define MANUAL_REC							(FALSE)					//Enable manual video recordings
#define AUTO_REC							(FALSE)					//Automatically start video capture 

#define PRINT_WORLD_COORDS					(FALSE)					//Print 3D World Coordinates (X,Y,Z) to Command line 	
#define PRINT_COORDS_TO_CSV					(FALSE)					//Print 3D World Coordinates (X,Y,Z) to CSV File
#define PRINT_INTR_PARA						(FALSE)					//Print intrinsic camera parameters (Camera matrix and distortion coefficients)
#define PRINT_ROT_MATRIX					(FALSE)					//Print rotation matrix for each detected marker
#define SHOW_FRAME_CENTER					(TRUE)					//Show principal point on image
#define SHOW_FRAME_COORD_SYS				(TRUE)					//Show xy-coordinate system on image

#define SERIAL_TRANSMIT						(TRUE)					//Enable/Disable Serial Transmission
#define SERIAL_READ_DATA					(TRUE)					//READ Data from Serial
#define PRINT_SERIAL_MSG_TO_CL				(FALSE)					//Print the Serial Message to Command Line. This is what is being sent to the robots

	/* SAVE COORDINATES TO CSV */
#define CSV_SAVE_ID							(TRUE)					//Set to true if id should be saved as well
#define CSV_USE_COMMA						(TRUE)					//Use a comma as decimal separator 
#define CSV_SEPARATOR						";"
#define CSV_OUTPUT_FILENAME					"datanew.csv"
#define CSV_REMOVE_AT_START					(TRUE)					//Set to true if old csv file should be removed at start 
#define CSV_NO_ID							(-1)
#define CSV_SAVE_TIME						(TRUE)					//Save timestamp for each measurement

	/* CAMERA SETUP */
#define FRAME_WIDTH							(2592)					//Camera image width
#define FRAME_HEIGHT						(2048)					//Camera image height
#define MS_BETWEEN_FRAMES					(10)					//wait 10ms before grabbing new frame, may impact performance
#define REC_FPS								(2.5)


	/* ARUCO SETUP */
#define ARUCO_DICT							(aruco::DICT_4X4_50)						//select the predefined Aruco dictionary
#define MARKER_LENGTH						(100)										//Marker length in mm (98 - 150)
#define MAX_NUMBER_OF_MARKERS				(12)										//How many markers/robots exist
#define NUM_OF_VARIABLES					(3)											//How many variables per robot (x, y, phi)
#define MAX_MSG_LENGTH ((MAX_NUMBER_OF_MARKERS)*(NUM_OF_VARIABLES))
#define ORIGIN_MARKER_ID					(25)										//Select which marker acts as the origin of world coordinate system
#define CALIB_FILE_NAME						"camera_parameters/calibration_basler7.xml" //This is the file where opencv takes the distortion coefficients and the camera matrix from

	/* Corner Refinement */
#define CR_ENABLE							(true)
#define CR_WIN_SIZE							(3)
#define CR_MAX_ITERATIONS					(50)
#define CR_MIN_ACCURACY						(0.1)

	/* ChAruco Camera Calibration */
#define CHARUCO_USE_INTRINSIC_GUESS			(TRUE)					//Has to be true if CHARUCO_FLAGS contains CV_CALIB_USE_INTRINSIC_GUESS
#define CHARUCO_FLAGS						(CV_CALIB_USE_INTRINSIC_GUESS | CV_CALIB_FIX_PRINCIPAL_POINT | CV_CALIB_RATIONAL_MODEL | CV_CALIB_FIX_ASPECT_RATIO)		//(CV_CALIB_USE_INTRINSIC_GUESS | CV_CALIB_FIX_PRINCIPAL_POINT | CV_CALIB_RATIONAL_MODEL | CV_CALIB_THIN_PRISM_MODEL | CV_CALIB_TILTED_MODEL)
#define CHARUCO_CAM_ID						(1)						//Select which camera to calibrate
#define CHARUCO_NUM_SQUARES_X				(4)
#define CHARUCO_NUM_SQUARES_Y				(6)
#define CHARUCO_SQUARE_LENGTH				(397)					//Charuco Board square length in pixel
#define CHARUCO_MARKER_LENGTH				(283)					//Charuco Board marker length in pixel
#define CHARUCO_SQUARE_LENGTH_M				(0.12165)				//Charuco Board square length in meter
#define CHARUCO_MARKER_LENGTH_M				(0.09405)				//Charuco Board marker length in meter
#define CHARUCO_FOCAL_LENGTH_EST			(1667)					//Intrinsic guess of focal length
#define CHARUCO_REFIND_STRATEGY				(FALSE)					//Use refind strategy to find markers based on previously found markers
#define CHARUCO_FILENAME_CALIB				"camera_parameters/calibration_basler7.xml"  //Name of output file of generated calibration parameters
#define CHARUCO_ASPECT_RATIO				(1)
#define CHARUCO_PRINT_FINAL					(TRUE)
#define CHARUCO_SHOW_CHESSBOARD_CORNERS		(TRUE)					//Show detected Charuco Corners on Image

	/* CONSTANTS */
#define MOVING_AVG_SAMPLES					(1)						// Amount of measurements used in Moving Average

	/* ERROR CODES */
#define ERR_OK								(0u)	
#define ERR_INV_PARAM_FILE					(1u)
#define ERR_NO_ORIGIN						(2u)
#define ERR_SERIAL_CONFIG					(3u)
#define ERR_FILE_NOT_OPEN					(4u)

#define CHARUCO_ERR_NOT_ENOUGH_FRAMES		(5u)
#define CHARUCO_ERR_NOT_ENOUGH_CORNERS		(6u)
#define CHARUCO_ERR_CALIB_FILE				(7u)

/* Commands that are sent to Sumos */
#define VAR_INVALID							(0x8000u)				//Send this instead of coordinates if marker was not detected
#define VAR_SWRESET							(0x7F00u)				//Invoke software reset
#define VAR_IDLE							(0x7F11u)				//Go to IDLE application state 
#define VAR_READY							(0x7F22u)				//Go to NORMAL application state
#define VAR_TRANS							(0x7F33u)				//Start next transition


#define ERR_STR_NO_ORIGIN					"No Origin Marker detected"
#define ERR_STR_NO_MARKER					"No Marker detected"