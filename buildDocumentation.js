#! /usr/bin/env node

'use strict';
const fs = require('fs');
const markdown = require('marked');

const readme = fs.readFileSync('README.md', 'utf-8');
const htmlReadme = markdown(readme);

fs.writeFileSync('docs/README.html', htmlReadme);