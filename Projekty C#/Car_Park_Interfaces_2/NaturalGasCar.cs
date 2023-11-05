using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class NaturalGasCar : ICar, INaturalGasCar
    {
        public bool InternalCombustionEngine { get; set; }
        public bool NaturalGasTank { get; set; }

        public void Start()
        {
            if (InternalCombustionEngine)
            {
                Console.WriteLine("The natural gas car is already running");
            }
            else
            {
                Console.WriteLine("Starting the natural gas car");
                InternalCombustionEngine = true;
            }
        }

        public void Stop()
        {
            if (InternalCombustionEngine)
            {
                InternalCombustionEngine = false;
                Console.WriteLine("Natural Gas: Stopping internal combustion engine...");
            }
            else
            {
                Console.WriteLine("Natural Gas: Internal combustion engine stopped.");
            }
        }

        public void Refuel()
        {
            RefuelNaturalGas();
        }
        public void RefuelNaturalGas()
        {
            if(NaturalGasTank)
            {
                Console.WriteLine("Gasoline tank is alreafy refueled.");
            }
            else
            {
                NaturalGasTank = true;
                Console.WriteLine("Filling Gasoline tank...");
            }
        }

        public void Drive()
        {
            DriveOnNaturalGas();
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