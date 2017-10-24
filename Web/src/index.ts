import { MoveService, Type } from "./moveService"

let moveType = Type.NOR
let pokemonTypeOne = Type.NOR
let pokemonTypeTwo: Type
let severityEl = document.getElementById("severity")

let moveTypeDropown = <HTMLSelectElement>document.getElementById("moveTypeDropown");
let pokemonTypeDropdownOne = <HTMLSelectElement>document.getElementById("pokemonTypeDropdownOne");
let pokemonTypeDropdownTwo = <HTMLSelectElement>document.getElementById("pokemonTypeDropdownTwo");
let dropDownElements = [moveTypeDropown, pokemonTypeDropdownOne, pokemonTypeDropdownTwo]
addOptions()
moveTypeDropown.selectedIndex = 0
pokemonTypeDropdownOne.selectedIndex = 0
pokemonTypeDropdownTwo.selectedIndex = 18

moveTypeDropown.onchange = (e) => {
    moveType = Type[moveTypeDropown.value as keyof typeof Type];
    handleDropdownChange()
}
pokemonTypeDropdownOne.onchange = (e) => {
    pokemonTypeOne = Type[pokemonTypeDropdownOne.value as keyof typeof Type];
    handleDropdownChange()
}

pokemonTypeDropdownTwo.onchange = (e) => {
    pokemonTypeTwo = Type[pokemonTypeDropdownTwo.value as keyof typeof Type];
    handleDropdownChange()
}

function addOptions() {
    let typeList = Object.getOwnPropertyNames(Type).slice(18)
    typeList.sort()
    for (var i = 0; i < typeList.length; i++) {
        for (var j = 0; j < dropDownElements.length; j++) {
            var option = document.createElement("option")
            option.text = typeList[i]
            dropDownElements[j].add(option)
        }
    }
    var option = document.createElement("option")
    option.text = "NIL"
    dropDownElements[2].add(option)
}

function handleDropdownChange() {
    if (pokemonTypeTwo === undefined)
        var severity = MoveService.attackMultiplier(moveType, pokemonTypeOne)
    else
        var severity = MoveService.attackMultiplierTwoTypes(moveType, pokemonTypeOne, pokemonTypeTwo)

    severityEl.innerText = severity.toString()
}
handleDropdownChange()