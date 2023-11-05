using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class GasolineCar : ICar, IGasolineCar
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
                Console.WriteLine("Out of gasoline, refuel needed");
            }
            else if (!isRunning)
            {
                Console.WriteLine("The car is not running");
            }
            else
            {
                Console.WriteLine("The car is driving on gasoline");
                isFueled = false;
            }
        }

        public void RefuelGasoline()
        {
            if (isFueled)
            {
                Console.WriteLine("The car is already refueled with gasoline");
            }
            else
            {
                Console.WriteLine("Refueling with gasoline");
                isFueled = true;
            }
        }

        public void FillTank()
        {
            RefuelGasoline();
        }
    }
}