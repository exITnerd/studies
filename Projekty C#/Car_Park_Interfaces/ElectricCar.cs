using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class ElectricCar : ICar, IElectricCar
    {
        private bool isRunning = false;
        private bool isCharged = false;
        public void Start()
        {
            if (isRunning)
            {
                Console.WriteLine("The car is already running");
            }
            else
            {
                Console.WriteLine("Starting the car");
                isRunning = true;
            }
        }
        public void Stop()
        {
            if (!isRunning)
            {
                Console.WriteLine("The engine is already turned off");
            }
            else
            {
                Console.WriteLine("Turning off the engine");
                isRunning = false;
            }
        }
        public void Drive()
        {
            if (!isCharged)
            {
                Console.WriteLine("The battery is discharged, plan to recharge it");
            }
            else if (!isRunning)
            {
                Console.WriteLine("The car is not running");
            }
            else
            {
                Console.WriteLine("The car is driving on electricity");
                isCharged = false;
            }
        }
        public void ChargeBattery()
        {
            if (isCharged)
            {
                Console.WriteLine("The battery is already charged, you can drive");
            }
            else
            {
                Console.WriteLine("Charging the battery");
                isCharged = true;
            }
        }

        public void FillTank()
        {
            ChargeBattery();
        }
    }
}