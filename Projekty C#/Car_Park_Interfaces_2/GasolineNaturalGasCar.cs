using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class GasolineNaturalGasCar : ICar, IGasolineCar, INaturalGasCar
    {
        public bool InternalCombustionEngine { get; set; }
        public bool GasolineTank { get; set; }
        public bool NaturalGasTank { get; set; }

        public void Start()
        {
            if (InternalCombustionEngine)
            {
                Console.WriteLine("The GasolineNaturalGas car is already started.");
            }
            else
            {
                Console.WriteLine("Starting the GasolineNaturalGas car...");
                InternalCombustionEngine = true;
            }
        }

        public void Stop()
        {
            if (InternalCombustionEngine)
            {
                InternalCombustionEngine = false;
                Console.WriteLine("GasolineNaturalGas: Stopping engine...");
            }
            else
            {
                Console.WriteLine("GasolineNaturalGas: engine stopped.");
            }
        }

        public void Refuel()
        {
            RefuelNaturalGas();
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
        public void RefuelNaturalGas()
        {
            if (NaturalGasTank)
            {
                Console.WriteLine("Natural Gas tank is alreafy refueled.");
            }
            else
            {
                NaturalGasTank = true;
                Console.WriteLine("Filling Natural Gas tank...");
            }
        }
        public void Drive()
        {
            DriveOnGasoline();
            DriveOnNaturalGas();
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
        public void DriveOnNaturalGas()
        {
            if (InternalCombustionEngine && NaturalGasTank)
            {
                Console.WriteLine("Driving on Natural Gas.");
                NaturalGasTank = false;
            }
            else if (!InternalCombustionEngine)
            {
                Console.WriteLine("The engine is not started!");
            }
            else
            {
                Console.WriteLine("The car is already driving on Natural Gas.");
            }
        }
    }
}