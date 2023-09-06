function roll(tableID) {

  //get input from dice roller
  const select_dice =  document.getElementById("diceType")
  const input_dice_result = document.getElementById("result");
  const input_mod = document.getElementById("modifier");
  const input_total = document.getElementById("total")

  //get values
  const sides = select_dice.value;
  const mod = input_mod.value;
  //using the Math.random() function, generate a number between 1 and the max value of the chosen di
  const di =  Math.floor(Math.random() * sides) + 1;
  //evaluate the sum of the number rolled plus the modifier
  const total = eval(di + "+" + mod);

  //change background colour of the dice results to green if the number is the highest possible value
  if(di == sides)
  {
    input_dice_result.style.background = "#7e8e65"
  }
  //change background colour of the dice results to red if the number is 1
  else if(di == 1)
  {
    input_dice_result.style.background = "#b65149"
  }
  else
  {
    input_dice_result.style.background = "#FFFFFF"
  }

  //display results
  input_dice_result.value = di;
  input_mod.value = mod;
  input_total.value = total;
}
