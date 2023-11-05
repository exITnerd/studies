using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class GasolineElectricCar : ICar, IGasolineCar, IElectricCar
    {
        public bool InternalCombustionEngine { get; set; }
        public bool ElectricEngine { get; set; }
        public bool GasolineTank { get; set; }
        public bool Battery { get; set; }

        public void Start()
        {
            if (InternalCombustionEngine)
            {
                Console.WriteLine("The gasoline engine is already started.");
            }
            else if (ElectricEngine)
            {
                Console.WriteLine("The electric engine is already started.");
            }
            else if (!InternalCombustionEngine & ElectricEngine)
            {
                Console.WriteLine("Starting the electric engine...");
                ElectricEngine = true;
            }
            else
            {
                Console.WriteLine("Starting the gasoline engine...");
                InternalCombustionEngine = true;
                ElectricEngine = false;
            }
        }

        public void Stop()
        {
            if (!InternalCombustionEngine)
            {
                Console.WriteLine("The gasoline engine is already stopped.");
            }
            else if (!ElectricEngine)
            {
                Console.WriteLine("The electric engine is already stopped.");
            }
            else if (!InternalCombustionEngine & ElectricEngine)
            {
                Console.WriteLine("Stopping the gasoline engine...");
                InternalCombustionEngine = false;
            }
            else
            {
                Console.WriteLine("Stopping the electric engine...");
                ElectricEngine = false;
            }
        }

        public void Refuel()
        {
            RefuelGasoline();
            ChargeBattery();
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
        public void ChargeBattery()
        {
            if (Battery)
            {
                Console.WriteLine("Battery is already charged.");
            }
            else
            {
                Battery = true;
                Console.WriteLine("Charging battery...");
            }
        }
        public void Drive()
        {
            DriveOnGasoline();
            DriveOnElectricity();
        }
        public void DriveOnGasoline()
        {
            if (InternalCombustionEngine && GasolineTank)
            {
                Console.WriteLine("Driving on Gasoline.");
                GasolineTank = false;
                ElectricEngine = true;
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
        public void DriveOnElectricity()
        {
            if (ElectricEngine && Battery)
            {
                Console.WriteLine("Driving on Electricity.");
                Battery = false;
            }
            else if (!ElectricEngine)
            {
                Console.WriteLine("The engine is not started!");
            }
            else
            {
                Console.WriteLine("The car is already driving on Electricity.");
            }
        }
    }

}