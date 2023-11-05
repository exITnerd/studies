using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class GasolineCar : ICar, IGasolineCar
    {
        public bool InternalCombustionEngine { get; set; }
        public bool GasolineTank { get; set; }

        public void Start()
        {
            if (InternalCombustionEngine)
            {
                Console.WriteLine("The gasoline car is already running");
            }
            else
            {
                Console.WriteLine("Starting the gasoline car");
                InternalCombustionEngine = true;
            }
        }

        public void Stop()
        {
            if (InternalCombustionEngine)
            {
                InternalCombustionEngine = false;
                Console.WriteLine("Gasoline: Stopping internal combustion engine...");
            }
            else
            {
                Console.WriteLine("Gasoline: Internal combustion engine stopped.");
            }
        }

        public void Refuel()
        {
            RefuelGasoline();
        }
        public void RefuelGasoline()
        {
            if (GasolineTank)
            {
                Console.WriteLine("Gasoline tank is alreafy refueled.");
            }
            else
            {
                GasolineTank = true;
                Console.WriteLine("Filling Gasoline tank...");
            }
        }

        public void Drive()
        {
            DriveOnGasoline();
        }
        public void DriveOnGasoline()
        {
            if (InternalCombustionEngine && GasolineTank)
            {
                Console.WriteLine("Driving on Gasoline.");
                GasolineTank = false;
            }
            else if (!InternalCombustionEngine)
            {
                Console.WriteLine("The engine is not started!");
            }
            else
            {
                Console.WriteLine("The car is already driving on Gasoline.");
            }
        }
    }
}