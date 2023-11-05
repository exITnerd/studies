using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class ElectricCar : ICar, IElectricCar
    {
        public bool ElectricEngine { get; set; }
        public bool Battery { get; set; }

        public void Start()
        {
            if (ElectricEngine)
            {
                Console.WriteLine("The electric car is already running");
            }
            else
            {
                Console.WriteLine("Starting the electric car");
                ElectricEngine = true;
            }
        }

        public void Stop()
        {
            if (ElectricEngine)
            {
                ElectricEngine = false;
                Console.WriteLine("Electric: Stopping engine...");
            }
            else
            {
                Console.WriteLine("Electric: engine stopped.");
            }
        }

        public void Refuel()
        {
            ChargeBattery();
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
            DriveOnElectricity();
        }
        public void DriveOnElectricity()
        {
            if (ElectricEngine && Battery)
            {
                Console.WriteLine("Driving on Electrcity.");
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