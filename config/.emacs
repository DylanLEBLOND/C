;;Environnement
(set-language-environment "UTF-8")

;;Fichiers Temporaires ~
(setq make-backup-files nil)

;;Affichage
(menu-bar-mode -1)
(column-number-mode t)
(setq-default c-basic-offset 4)
(setq-default c-default-style "linux")
(setq-default tab-width 4)
(setq-default indent-tabs-mode t)
(setq-default tab-stop-list '(4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 104 108 112 116 120))
(column-number-mode 1)
(setq linum-format "%3d ")
(show-paren-mode 1)

;;Raccourcis
(global-set-key [f8] 'undo)
(global-set-key (kbd "C-z") 'undo)
(global-set-key [f9] 'redo)
(global-set-key (kbd "C-S-z") 'redo)
(global-set-key (kbd "C-v") 'yank)
(global-set-key (kbd "<kp-0>") 0)
(global-set-key (kbd "<kp-1>") 1)
(global-set-key (kbd "<kp-2>") 2)
(global-set-key (kbd "<kp-3>") 3)
(global-set-key (kbd "<kp-4>") 4)
(global-set-key (kbd "<kp-5>") 5)
(global-set-key (kbd "<kp-6>") 6)
(global-set-key (kbd "<kp-7>") 7)
(global-set-key (kbd "<kp-8>") 8)
(global-set-key (kbd "<kp-9>") 9)
