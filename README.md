# BounceBall
bounceball sfml version.

## developer
- snowbear1472 (snowbear1472@gmail.com)

## game structure
client doesn't create directories automatically

- root: based game directory
- root/res: resource directory
- root/res/entity: a directory which is store entity scripts.
- root/res/object: a directory which is store object scripts.
- root/res/font: a directory which is store font files.
- root/res/map: a directory which is store map datas.

## script
all of bounceball's script type is csv.

### script meta data
- file_type: should be "bounceball_script"
              * usage: file_type, bounceball_script
- data_type: script data type
              * usage: data_type, {value}
              * type of data
                * bounceball:entity
                * bounceball:objcet
- name: name of script
              * reserved words
                * default_ball
                * default_grass
- developer: developer of script
- details: details of script

<pre><code>
file_type, bounceball_script
data_type, bounceball:entity
name, default_ball
developer, snowbear1472
details, default ball
</code></pre>

#### bounceball:entity
- entity_name: name of entity
- size: size of entity
- color: color of entity
- texture: texuture of entity
- animation: animation of entity
-

## about
this project is test-type. real game is upcomming soon :D
