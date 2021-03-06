
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)

# fm19rte (BETA)

Read and write memory for FM19 (Football Manager 2019)

Grafic Example : https://ug-code.github.io/fm19RTE/app

## System Requirement
```
If you are using C++
   visual Studio 2015 C++

If you are using Nodejs
  C++ Nodejs Addons
  const fm19js = require('./build/Release/fm19js.node');
  nodejs backend for C++ api   : expressjs
  nodejs frontend              : angularjs
```

## How to work

```js
For Nodejs

npm install
npm run cpp-build
npm run startNodeman or npm start

```

## Support
fm 19 v19.1.1 1159619 (64)


## Usage

 If you are using C++
```c++
HANDLE phandle = GameLoad(windowName);
ServiceClub serviceClub;
cout << "Current Team                    :" << serviceClub.getClubFullname(phandle) << endl;
cout << "Current repulation              :" << serviceClub.getClubReputation(phandle) << endl;
cout << "Current competition             :" << serviceClub.getClubCompetition(phandle) << endl;
cout << "Current nation                  :" << serviceClub.getClubNation(phandle) << endl;
cout << "Current money value             :" << serviceClub.getClubMoney(phandle) << endl;
cout << "Please enter an new money value : ";
cin >> newMoney;
serviceClub.setClubMoney(phandle, newMoney);
```
If you are using NodeJs
```c++
const fm19js = require('./build/Release/fm19js.node');
console.log(fm19js.myProfile()); 
/*
{ reputation: { getHomeRep: 5043, getCurrentRep: 550, getWorldRep: 1471 },
  characteristic:
   { getHandsOnApproach: 50,
     getTacticalConsistency: 50,
     getClubPlayerLoyalty: 50,
     getSquadDiscipline: 50,
     getFinancialControl: 50,
     getMediaHandling: 47 } }
*/     
     


```


## Cheating
#### Current Team
- Money base Address : 0x1469B91F0;
- Money base Offset  :{ 0x0,0x50,0x70,0x148,0x67C };


## Features

  - Add My Current Club section
  - Add Average Attendance to Club section
  - Add Minimum Attendance to Club section
  - Add Maximum Attendance to Club section
  - Add Tactical Attributes (including Formations) to Club section
  - Add Full Name to Player section
  - Add Morale to Player section


##  Changes Log:
  - Added Player List
  - Added Club List
  - v1.0 - Released 02-Feb-2019 
  - Added Money
  -First realeased

## Screen 
<img src="https://raw.githubusercontent.com/ug-code/fm19RTE/master/cpp/Resource/basic.JPG?" width="800" height="400"/>
<img src="https://raw.githubusercontent.com/ug-code/fm19RTE/master/cpp/Resource/playerList.JPG?" width="800" height="400"/>

## 🙌 Contribution
- We need more devs and support!
- Open pull request with improvements
- Discuss ideas in issues
- Alternatively, bug reporting is vital! Use the Github's Issues page to do that!

## Referance

https://stackoverflow.com/questions/48208782/read-memory-of-process-c

https://nodejs.org/api/addons.html

##  License
fm19RTE is released under the GNU General Public License v2.0 Please read the LICENSE file for a full version of the License


