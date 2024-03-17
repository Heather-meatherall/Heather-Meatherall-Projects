function roll(tableID) {
  //get input from dice roller
  const select_dice =  document.getElementById("diceType")
  const input_amount = document.getElementById("diceNum")
  const input_dice_result = document.getElementById("result");
  const input_mod = document.getElementById("modifier");
  const input_total = document.getElementById("total")

  //get values
  const sides = select_dice.value;
  const mod = input_mod.value;
  const amount = input_amount.value
  let dice = 0;
  const diceRolls = [];

  for(let i = 0; i < amount; i++)
  {
    //using the Math.random() function, generate a number between 1 and the max value of the chosen di
    const di =  Math.floor(Math.random() * sides) + 1
    dice = dice + di;
    diceRolls.push(di);
  }

  //evaluate the sum of the number rolled plus the modifier
  const total = eval(dice + "+" + mod);

  //display results
  input_dice_result.value = diceRolls;
  input_mod.value = mod;
  input_total.value = total;
}

const total = []
const diceRolls = []
function rollHitPoints(tableID) {
  const input_stat1 = document.getElementById("stat1")
  const input_stat2 = document.getElementById("stat2")
  const input_stat3 = document.getElementById("stat3")
  const input_stat4 = document.getElementById("stat4")
  const input_stat5 = document.getElementById("stat5")
  const input_stat6 = document.getElementById("stat6")

  const input_rolls1 = document.getElementById("rolls1")
  const input_rolls2 = document.getElementById("rolls2")
  const input_rolls3 = document.getElementById("rolls3")
  const input_rolls4 = document.getElementById("rolls4")
  const input_rolls5 = document.getElementById("rolls5")
  const input_rolls6 = document.getElementById("rolls6")

  let min = []
  for (let i = 0; i < 6; i++) {
    di1 =  Math.floor(Math.random() * 6) + 1;
    di2 =  Math.floor(Math.random() * 6) + 1;
    di3 =  Math.floor(Math.random() * 6) + 1;
    di4 =  Math.floor(Math.random() * 6) + 1;

    total.push((di1 + di2 + di3 + di4) - Math.min(di1, di2, di3, di4))
    diceRolls.push([di1, di2, di3, di4])
  }

  input_stat1.value = total[0]
  input_stat2.value = total[1]
  input_stat3.value = total[2]
  input_stat4.value = total[3]
  input_stat5.value = total[4]
  input_stat6.value = total[5]

  input_rolls1.value = diceRolls[0]
  input_rolls2.value = diceRolls[1]
  input_rolls3.value = diceRolls[2]
  input_rolls4.value = diceRolls[3]
  input_rolls5.value = diceRolls[4]
  input_rolls6.value = diceRolls[5]

}

function sort(tableID, sortType)
{
  const input_stat1 = document.getElementById("stat1")
  const input_stat2 = document.getElementById("stat2")
  const input_stat3 = document.getElementById("stat3")
  const input_stat4 = document.getElementById("stat4")
  const input_stat5 = document.getElementById("stat5")
  const input_stat6 = document.getElementById("stat6")

  const input_rolls1 = document.getElementById("rolls1")
  const input_rolls2 = document.getElementById("rolls2")
  const input_rolls3 = document.getElementById("rolls3")
  const input_rolls4 = document.getElementById("rolls4")
  const input_rolls5 = document.getElementById("rolls5")
  const input_rolls6 = document.getElementById("rolls6")


  if(sortType == 0)
 {
   total.sort(function(a, b){return a - b});
 }
 else
 {
   total.sort(function(a, b){return b - a});
 }

  input_stat1.value = total[0]
  input_stat2.value = total[1]
  input_stat3.value = total[2]
  input_stat4.value = total[3]
  input_stat5.value = total[4]
  input_stat6.value = total[5]

  input_rolls1.value = diceRolls[0]
  input_rolls2.value = diceRolls[1]
  input_rolls3.value = diceRolls[2]
  input_rolls4.value = diceRolls[3]
  input_rolls5.value = diceRolls[4]
  input_rolls6.value = diceRolls[5]
}


function deathSaves(tableID, diceElementId, buttonElementId)
{
  const death_dice =  document.getElementById(diceElementId)
  const death_button = document.getElementById(buttonElementId)

  //using the Math.random() function, generate a number between 1 and the max value of the chosen di
  const di =  Math.floor(Math.random() * 20) + 1

  //change background colour of the dots based on the dice roll
  if(di >=10)
  {
    death_dice.style.backgroundColor = "#932F6D"
    death_button.style.backgroundColor = "#932F6D"
    death_dice.value = "Pass"
  }
  else
  {
    death_dice.style.backgroundColor = "#420039"
    death_dice.style.color = "#932F6D"
    death_button.style.backgroundColor = "#420039"
    death_button.style.color = "#420039"
    death_button.style.borderColor = "#420039"

    death_dice.value = "Fail"
  }

}
