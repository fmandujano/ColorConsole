// ColorConsole.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime> 

#define LOGFILENAME "log.txt"

//se leeria desde la config
int GameVerbosity = 2;

std::fstream logfile;

//enum de canales
enum ConsoleChannel{
    Render,Audio,Input,Phys,Assets,Game
};

//inicializar el sistema de log
void InitLog()
{
    auto nowtime = std::chrono::system_clock::now();
    std::time_t now = std::chrono::system_clock::to_time_t(nowtime);
    logfile.open(LOGFILENAME, std::ios::out);
    if (logfile.is_open())
    {
        logfile << "[" << std::ctime(&now) << "] ";
        logfile << "Logfile open \n";
    }
}

//tres niveles de verbosidad: 0 error, 1 warn, 2 info
//en todos los casos escribe a archivo
void Log(int verbosity, ConsoleChannel channel, const char * msg )
{
    if (verbosity == 0)
    {
        std::cout << "\033[31m";  //rojo error
    }
    else if (verbosity == 1)
    {
        std::cout << "\033[33m";  //amarillo cuidado
    }
    else if (verbosity == 2)
    {
        std::cout << "\033[32m";  //verde todo bien
    }

    if (verbosity <= GameVerbosity)
    {
        switch (channel)
        {
            case ConsoleChannel::Render:
                std::cout << "LogRenderManager: ";
                logfile << "LogRenderManager: ";
                break;
            case ConsoleChannel::Audio:
                std::cout << "LogAudioManager: ";
                logfile<< "LogAudioManager: ";
                break;
            case ConsoleChannel::Input:
                std::cout << "LogInputManager: ";
                logfile << "LogInputManager: ";
                break;
            case ConsoleChannel::Phys:
                std::cout << "LogPhysics: ";
                logfile << "LogPhysics: ";
                break;
            case ConsoleChannel::Assets:
                std::cout << "LogAssetsManager: ";
                logfile << "LogAssetsManager: ";
                break;
            case ConsoleChannel::Game:
                std::cout << "LogGameManager: ";
                logfile << "LogGameManager: ";
                break;
        }
        std::cout << msg << std::endl;
        logfile << msg << std::endl;

    }
    //regresar al color neutro
    std::cout << "\033[0m";
}


int main()
{
    InitLog();
    Log(1, ConsoleChannel::Render, "inicializando render manager");
    Log(1, ConsoleChannel::Audio, "init audio");
    Log(2, ConsoleChannel::Game, "hola mundo");
    Log(0, ConsoleChannel::Game, "no hay juego para cargar :(");

    system("pause");
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
