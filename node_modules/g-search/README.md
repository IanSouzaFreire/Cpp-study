# g-search

Super fast searching of globally installed node modules

```
$ npm i g-search
```

## gSearch(query)

**query** `String|RegExp` (optional)

Query used for searching globally installed node modules. If left blank, all globally installed modules will be returned.

```js
const gSearch = require('g-search')

gSearch('bower').then(modules => console.log(modules))
// [{ name: 'bower', version: '1.8.0' }, { name: 'bower-art-resolver', version: '2.0.8' }]
```

## Speed / Performance

The below test was performed multiple times and the fastest time has been recorded. On average the search took **~6.500ms**.

```
> g-search: 3.045ms
[ { name: 'bower-art-resolver', version: '2.0.8' },
  { name: 'bower', version: '1.8.0' },
  { name: 'cli', version: '1.0.1' },
  { name: 'cordova', version: '6.4.0' },
  { name: 'elf.cli', version: '1.0.5' },
  { name: 'eslint-config-airbnb', version: '14.0.0' },
  { name: 'eslint-plugin-html', version: '2.0.1' },
  { name: 'eslint-plugin-import', version: '2.2.0' },
  { name: 'eslint-plugin-jsx-a11y', version: '3.0.2' },
  { name: 'eslint-plugin-react', version: '6.9.0' },
  { name: 'eslint', version: '3.13.1' },
  { name: 'gulp', version: '3.9.1' },
  { name: 'http-server', version: '0.9.0' },
  { name: 'install-peerdeps', version: '1.1.2' },
  { name: 'ios-deploy', version: '1.9.0' },
  { name: 'npm', version: '3.10.9' },
  { name: 'vue-cli', version: '2.5.1' },
  { name: 'webpack', version: '1.13.3' } ]
```

The same test, using `npm ls`, took on average **~3650.00ms**. That's nearly 600 times longer!

```
> npm ls --global --depth=0: 3519.564ms
/usr/local/lib
├── bower@1.8.0
├── bower-art-resolver@2.0.8
├── cli@1.0.1
├── cordova@6.4.0
├── elf.cli@1.0.5
├── eslint@3.13.1
├── eslint-config-airbnb@14.0.0
├── eslint-plugin-html@2.0.1
├── eslint-plugin-import@2.2.0
├── eslint-plugin-jsx-a11y@3.0.2
├── eslint-plugin-react@6.9.0
├── gulp@3.9.1
├── http-server@0.9.0
├── install-peerdeps@1.1.2
├── ios-deploy@1.9.0
├── npm@3.10.9
├── vue-cli@2.5.1
└── webpack@1.13.3
```
