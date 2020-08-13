#!/usr/bin/node

const request = require('request');

const filmNum = process.argv[2] + '/';
const filmUrl = 'https://swapi-api.hbtn.io/api/films/';

request(filmUrl + filmNum, function (err, res, body) {
  if (err) {
    return console.error(err);
  }

  const characterList = JSON.parse(body).characters;

  characterList.forEach(function (characterUrl) {
    request(characterUrl, function (err, res, body) {
      if (err) {
        return console.error(err);
      }

      const characterName = JSON.parse(body).name;
      console.log(characterName);
    });
  });
});
