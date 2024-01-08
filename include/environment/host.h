/**
 * \file
 * \author       Kavalchuk Aliaksandr (aliaksander.kavalchuk@gmail.com)
 * \brief        Host depend constants
 */

#pragma once

//_____ I N C L U D E S _______________________________________________________
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    // Windows (x86 or x64)
    #define FILE_SPLITTER '\\'
#elif defined(__linux__)
    // Linux
    #define FILE_SPLITTER '/'
#elif defined(__APPLE__) && defined(__MACH__)
    // Mac OS
    #define FILE_SPLITTER '/'
#elif defined(unix) || defined(__unix__) || defined(__unix)
    // Unix like OS
    #define FILE_SPLITTER '/'
#else
    #error Unknown host OS!
#endif
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
