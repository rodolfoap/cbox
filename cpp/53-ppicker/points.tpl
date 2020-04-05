%YAML:1.0
---
image_points: !!opencv-matrix
    rows: {{rows}}
    cols: 2
    dt: i
    data: [
        {{#coorduv}}
        {{x}}, {{y}},
        {{/coorduv}}
]
world_points: !!opencv-matrix
    rows: {{rows}}
    cols: 2
    dt: d
    data: [
        {{#coordxy}}
        {{x}}, {{y}}, # {{c}}
        {{/coordxy}}
]
