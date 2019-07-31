#! /usr/bin/env node

'use strict';
const fs = require('fs');
const markdownToHTML = require('marked');

const readme = fs.readFileSync('README.md', 'utf-8');
const htmlReadme = markdownToHTML(readme);

fs.writeFileSync('docs/README.html', htmlReadme);