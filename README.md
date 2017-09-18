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
+ file_type: should be "bounceball_script".
  + usage: <code>file_type, bounceball_script</code>
+ data_type: script data type.
  + usage: data_type, {value}
  + type of data
    + bounceball:entity
    + bounceball:objcet
+ name: name of script.
    + reserved words
      + default_ball
      + default_grass
+ developer: developer of script.
+ details: details of script.

###### example code
<pre><code>file_type, bounceball_script
data_type, bounceball:entity
name, default_ball
developer, snowbear1472
details, default ball</code></pre>

#### bounceball:entity
+ entity_name: name of entity.
  + usage: entity_name, {name}
+ size: size of entity.
  + usage: size, ({width}, {height})
+ color: color of entity.
  + usage: color, ({r}, {g}, {b}, {a})
+ texture: texuture of entity.
  + usage: texture, "{file_name}", ({x}, {y}), ({width}, {height})
    + file_name: client find file automatically. don't write full path. the resource should be in res directory.
+ animation: animation of entity.
  + usage: animation, {frame_size}
+ frame: frame of entity's animation.
  + usage: frame, {second}, {second}, ...
  
<pre><code>entity_name, ball
size, (30, 30)
color, (255, 255, 255, 255)
texture, "ball.png", (0, 0), (30, 30)
animation, 30
frame, 0.45, 0.34, 0.13</code></pre>

#### bounceball:object
+ object_name: name of object.
  + usage: object_name, {name}
+ size: size of object.
  + usage: size, ({width}, {height})
+ color: color of object.
  + usage: color, ({r}, {g}, {b}, {a})
+ texture: texture of object.
  + usage: texture, "{file_name}", ({x}, {y}), ({width}, {height})
    + file_name: client find file automatically. don't write full path. the resource should be in res directory.

<pre><code>object_name, grass
size, (50, 50)
color, (255, 255, 255, 255)
texture, "grass.png", (0, 0), (50, 50)</code></pre>

## about
this project is test-type. real game is upcomming soon :D
