;;;; -*- Mode: Lisp ; Package: Toolkit-Internals -*-
;;;
;;; **********************************************************************
;;; This code was written as part of the CMU Common Lisp project at
;;; Carnegie Mellon University, and has been placed in the public domain.
;;;
(ext:file-comment
  "$Header: /project/cmucl/cvsroot/src/motif/lisp/string-base.lisp,v 1.2 1994/10/31 04:54:48 ram Exp $")
;;;
;;; **********************************************************************
;;;
;;; Written by Michael Garland
;;;
;;; This is the database of strings used for tokenizing communications
;;; between Lisp and C.
;;;

(in-package "TOOLKIT-INTERNALS")

;;; This table MUST be *SORTED*.
(setf *toolkit-string-table*
      (vector
       "accelerator"
       "acceleratorText"
       "accelerators"
       "activateCallback"
       "adjustLast"
       "adjustMargin"
       "alignment"
       "allowResize"
       "allowShellResize"
       "ancestorSensitive"
       "applyCallback"
       "applyLabelString"
       "armCallback"
       "armColor"
       "armPixmap"
       "autoShowCursorPosition"
       "automaticSelection"
       "background"
       "backgroundPixmap"
       "bitmap"
       "blinkRate"
       "borderColor"
       "borderPixmap"
       "borderWidth"
       "bottomAttachment"
       "bottomOffset"
       "bottomPosition"
       "bottomShadowColor"
       "bottomShadowPixmap"
       "bottomWidget"
       "browseSelectionCallback"
       "buttonAcceleratorText"
       "buttonAccelerators"
       "buttonCount"
       "buttonMnemonicCharSets"
       "buttonMnemonics"
       "buttonSet"
       "buttonType"
       "buttons"
       "cancelButton"
       "cancelCallback"
       "cancelLabelString"
       "cascadePixmap"
       "cascadingCallback"
       "children"
       "clipWindow"
       "colormap"
       "columns"
       "commandChangedCallback"
       "commandEnteredCallback"
       "commandWindow"
       "commandWindowLocation"
       "createPopupChildProc"
       "cursorPosition"
       "cursorPositionVisible"
       "decrementCallback"
       "defaultActionCallback"
       "defaultButton"
       "defaultButtonShadowThickness"
       "defaultFontList"
       "depth"
       "destroyCallback"
       "dialogTitle"
       "disarmCallback"
       "doubleClickInterval"
       "dragCallback"
       "editMode"
       "editType"
       "editable"
       "entryAlignment"
       "entryBorder"
       "entryCallback"
       "entryClass"
       "exposeCallback"
       "extendedSelectionCallback"
       "file"
       "fillOnArm"
       "fillOnSelect"
       "filterLabelString"
       "focusCallback"
       "font"
       "fontList"
       "forceBars"
       "foreground"
       "function"
       "gainPrimaryCallback"
       "height"
       "helpCallback"
       "helpLabelString"
       "highlight"
       "highlightColor"
       "highlightOnEnter"
       "highlightPixmap"
       "highlightThickness"
       "horizontalScrollBar"
       "iconMask"
       "iconName"
       "iconPixmap"
       "iconWindow"
       "increment"
       "incrementCallback"
       "index"
       "indicatorOn"
       "indicatorSize"
       "indicatorType"
       "initialDelay"
       "initialResourcesPersistent"
       "innerHeight"
       "innerWidth"
       "innerWindow"
       "inputCallback"
       "inputCreate"
       "insertPosition"
       "internalHeight"
       "internalWidth"
       "isAligned"
       "isHomogeneous"
       "itemCount"
       "items"
       "jumpProc"
       "justify"
       "labelInsensitivePixmap"
       "labelPixmap"
       "labelString"
       "labelType"
       "leftAttachment"
       "leftOffset"
       "leftPosition"
       "leftWidget"
       "length"
       "listLabelString"
       "listMarginHeight"
       "listMarginWidth"
       "listSizePolicy"
       "listSpacing"
       "listUpdated"
       "losePrimaryCallback"
       "losingFocusCallback"
       "lowerRight"
       "mainWindowMarginHeight"
       "mainWindowMarginWidth"
       "mapCallback"
       "mappedWhenManaged"
       "mappingDelay"
       "marginBottom"
       "marginHeight"
       "marginLeft"
       "marginRight"
       "marginTop"
       "marginWidth"
       "maxLength"
       "maximum"
       "menuAccelerator"
       "menuBar"
       "menuCursor"
       "menuEntry"
       "menuHelpWidget"
       "menuHistory"
       "menuPost"
       "messageString"
       "messageWindow"
       "minimum"
       "mnemonic"
       "mnemonicCharSet"
       "modifyVerifyCallback"
       "motionVerifyCallback"
       "multiClick"
       "multipleSelectionCallback"
       "name"
       "navigationType"
       "noMatchCallback"
       "notify"
       "numChildren"
       "numColumns"
       "okCallback"
       "okLabelString"
       "optionLabel"
       "optionMnemonic"
       "orientation"
       "outputCreate"
       "overrideRedirect"
       "packing"
       "pageDecrementCallback"
       "pageIncrement"
       "pageIncrementCallback"
       "paneMaximum"
       "paneMinimum"
       "parameter"
       "pendingDelete"
       "popdownCallback"
       "popupCallback"
       "popupEnabled"
       "postFromButton"
       "postFromCount"
       "postFromList"
       "processingDirection"
       "promptString"
       "radioAlwaysOne"
       "radioBehavior"
       "recomputeSize"
       "refigureMode"
       "repeatDelay"
       "resizable"
       "resize"
       "resizeCallback"
       "resizeHeight"
       "resizeWidth"
       "reverseVideo"
       "rightAttachment"
       "rightOffset"
       "rightPosition"
       "rightWidget"
       "rowColumnType"
       "rows"
       "sashHeight"
       "sashIndent"
       "sashShadowThickness"
       "sashWidth"
       "saveUnder"
       "scaleMultiple"
       "screen"
       "scrollBarDisplayPolicy"
       "scrollBarPlacement"
       "scrollDCursor"
       "scrollHCursor"
       "scrollHorizontal"
       "scrollLCursor"
       "scrollLeftSide"
       "scrollProc"
       "scrollRCursor"
       "scrollTopSide"
       "scrollUCursor"
       "scrollVCursor"
       "scrollVertical"
       "scrolledWindowMarginHeight"
       "scrolledWindowMarginWidth"
       "scrollingPolicy"
       "selectColor"
       "selectInsensitivePixmap"
       "selectPixmap"
       "selectThreshold"
       "selectedItemCount"
       "selectedItems"
       "selection"
       "selectionArray"
       "selectionArrayCount"
       "selectionLabelString"
       "selectionPolicy"
       "sensitive"
       "separatorOn"
       "set"
       "shadow"
       "shadowThickness"
       "showArrows"
       "showAsDefault"
       "showSeparator"
       "shown"
       "simpleCallback"
       "singleSelectionCallback"
       "sizePolicy"
       "skipAdjust"
       "sliderSize"
       "source"
       "space"
       "spacing"
       "string"
       "stringDirection"
       "subMenuId"
       "symbolPixmap"
       "textOptions"
       "textSink"
       "textSource"
       "thickness"
       "thumb"
       "thumbProc"
       "title"
       "titleString"
       "toBottomCallback"
       "toPositionCallback"
       "toTopCallback"
       "top"
       "topAttachment"
       "topItemPosition"
       "topOffset"
       "topPosition"
       "topShadowColor"
       "topShadowPixmap"
       "topWidget"
       "transient"
       "translations"
       "traversalOn"
       "traversalType"
       "troughColor"
       "unitType"
       "unmapCallback"
       "unselectPixmap"
       "update"
       "updateSliderSize"
       "useBottom"
       "useRight"
       "userData"
       "value"
       "valueChangedCallback"
       "verifyBell"
       "verticalScrollBar"
       "visibleItemCount"
       "visibleWhenOff"
       "visualPolicy"
       "whichButton"
       "width"
       "window"
       "windowGroup"
       "wordWrap"
       "workWindow"
       "x"
       "y"))
