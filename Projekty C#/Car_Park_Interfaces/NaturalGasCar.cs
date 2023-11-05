using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class NaturalGasCar : ICar, INaturalGasCar
    {
        private bool isRunning = false;
        private bool isFueled = false;

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
            if (!isFueled)
            {
                Console.WriteLine("Out of natural gas, refuel needed");
            }
            else if (!isRunning)
            {
                Console.WriteLine("The car is not running");
            }
            else
            {
                Console.WriteLine("The car is driving on natural gas");
                isFueled = false;
            }
        }

        public void RefuelNaturalGas()
        {
            if (isFueled)
            {
                Console.WriteLine("The car is already refueled with natural gas");
            }
            else
            {
                Console.WriteLine("Refueling with natural gas");
                isFueled = true;
            }
        }

        public void FillTank()
        {
            RefuelNaturalGas();
        }
    }
}