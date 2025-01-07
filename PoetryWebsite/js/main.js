let soliderResults = 0;
let poetResults = 0;
let kingResults = 0;

function savePoem()
{
    let title = document.getElementById('title');

    let verse1 = document.querySelector('#verse1').value;
    let verse2 = document.querySelector('#verse2').value;
    let verse3 = document.querySelector('#verse3').value;
    let verse4 = document.querySelector('#verse4').value;
    let verse5 = document.querySelector('#verse5').value;
    let verse6 = document.querySelector('#verse6').value;
    let verse7 = document.querySelector('#verse7').value;

    let verses = [verse1, verse2, verse3, verse4, verse5, verse6, verse7];

    for(let i = 0; i < verses.length; i++)
    {
        if (verses[i] == "Soilder")
        {
            soliderResults++;
        }
        else if (verses[i] == "Poet")
        {
            poetResults++;
        }
        else
        {
            kingResults++;
        }
    }


    if(Math.max(soliderResults, poetResults, kingResults) == soliderResults)
    {
      title.innerHTML =  "For the Solider"
    }
    else if (Math.max(soliderResults, poetResults, kingResults) == poetResults)
    {
        title.innerHTML = "For the Poet"
    }
    else
    {
        title.innerHTML = "For the King"
    }
  title.style.fontWeight = "bold"

}

function reset()
{
  soliderResults = 0;
  poetResults = 0;
  kingResults = 0;

  title.innerHTML = "Complete the Poem to Get Your Title!"
  title.style.fontWeight = "bold"

}
