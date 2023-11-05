using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Car_Park_Interfaces
{
    class GasolineNaturalGasCar : ICar, IGasolineCar, INaturalGasCar
    {
        private bool isRunning = false;
        private bool isFueledGas = false;
        private bool isFueledGasoline = false;
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
            if (!isFueledGas && !isFueledGasoline)
            {
                Console.WriteLine("Out of gasoline and electricity, refuel and charging needed");
            }
            else if (!isFueledGas && isFueledGasoline)
            {
                Console.WriteLine("No natural gas, driving on gasoline");
                isFueledGasoline = false;
            }
            else if (!isRunning)
            {
                Console.WriteLine("The car is not running");
            }
            else
            {
                Console.WriteLine("The car is driving on natural gas");
                isFueledGas = false;
            }
        }

        public void RefuelGasoline()
        {
            if (isFueledGasoline)
            {
                Console.WriteLine("The car is already refueled with gasoline");
            }
            else
            {
                Console.WriteLine("Refueling with gasoline");
                isFueledGasoline = true;
            }
        }

        public void RefuelNaturalGas()
        {
            if (isFueledGas)
            {
                Console.WriteLine("The car is already refueled with natural gas");
            }
            else
            {
                Console.WriteLine("Refueling with natural gas");
                isFueledGas = true;
            }
        }

        public void FillTank()
        {
            RefuelGasoline();
            RefuelNaturalGas();
        }
    }
}