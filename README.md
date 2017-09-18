# BounceBall
bounceball sfml version.

## developer
- snowbear1472 (snowbear1472@gmail.com)

## resource
client doesn't create directories automatically

### structure
- <code>root</code>: based game directory
- <code>root/res</code>: resource directory
- <code>root/res/entity</code>: a directory which is store entity scripts.
- <code>root/res/object</code>: a directory which is store object scripts.
- <code>root/res/font</code>: a directory which is store font files.
- <code>root/res/map</code>: a directory which is store map datas.

## script
all of bounceball's script type is csv.

###### example code
<pre><code>file_type, bounceball_script
data_type, bounceball:entity
name, default_ball
developer, snowbear1472
details, default ball


entity_name, ball
size, (30, 30)
color, (255, 255, 255, 255)
texture, "ball.png", (0, 0), (30, 30)
animation, 30
frame, 0.45, 0.34, 0.13</code></pre>

### script meta data
+ file_type: should be "bounceball_script".
  + usage: <code>file_type, bounceball_script</code>
+ data_type: script data type.
  + usage: <code>data_type, {value}</code>
  + type of data
    + <code>bounceball:entity</code>
    + <code>bounceball:objcet</code>
+ name: name of script.
  + usage: <code>name, {name}</code>
    + reserved words
      + <code>default_ball</code>
      + <code>default_grass</code>
+ developer: developer of script.
  + usage: <code>developer, {developer}</code>
+ details: details of script.
  + usage: <code>details, {details}</code>

###### example code
<pre><code>file_type, bounceball_script
data_type, bounceball:entity
name, default_ball
developer, snowbear1472
details, default ball</code></pre>

#### bounceball:entity
+ entity_name: name of entity.
  + usage: <code>entity_name, {name}</code>
+ size: size of entity.
  + usage: <code>size, ({width}, {height})</code>
+ color: color of entity.
  + usage: <code>color, ({r}, {g}, {b}, {a})</code>
+ texture: texuture of entity.
  + usage: <code>texture, "{file_name}", ({x}, {y}), ({width}, {height})</code>
    + file_name: client find file automatically. don't write full path. the resource should be in res directory.
+ animation: animation of entity.
  + usage: <code>animation, {frame_size}</code>
+ frame: frame of entity's animation.
  + usage: <code>frame, {second}, {second}, ...</code>

###### example code
<pre><code>entity_name, ball
size, (30, 30)
color, (255, 255, 255, 255)
texture, "ball.png", (0, 0), (30, 30)
animation, 30
frame, 0.45, 0.34, 0.13</code></pre>

#### bounceball:object
+ object_name: name of object.
  + usage: <code>object_name, {name}</code>
+ size: size of object.
  + usage: <code>size, ({width}, {height})</code>
+ color: color of object.
  + usage: <code>color, ({r}, {g}, {b}, {a})</code>
+ texture: texture of object.
  + usage: <code>texture, "{file_name}", ({x}, {y}), ({width}, {height})</code>
    + file_name: client find file automatically. don't write full path. the resource should be in res directory.

###### example code
<pre><code>object_name, grass
size, (50, 50)
color, (255, 255, 255, 255)
texture, "grass.png", (0, 0), (50, 50)</code></pre>

## about
this project is test-type. real game is upcomming soon :D
